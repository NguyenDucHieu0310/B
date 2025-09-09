import random as rd

def Violations():
    # Return the number of violations
    v = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            if x[i] == x[j]:  # i and j are on the same row
                v += 1
            if x[i] + i == x[j] + j:  # i and j are on the same diagonal
                v += 1
            if x[i] - i == x[j] - j:  # i and j are on the same diagonal
                v += 1
    return v

def ViolationOfQueen(q):
    # Return the number of violations of queen q
    v = 0
    for i in range(n):
        if i != q:
            if x[i] == x[q]:  # Same row
                v += 1
            if x[i] + i == x[q] + q:  # Same diagonal
                v += 1
            if x[i] - i == x[q] - q:  # Same diagonal
                v += 1
    return v

def SelectMostViolatingQueen():
    max_violations = 0
    select_queen = -1
    candidate = []  # Collect all the best neighbors
    for q in range(n):
        v = ViolationOfQueen(q)
        if v > max_violations:
            max_violations = v
            candidate = []
            candidate.append(q)
        elif v == max_violations:
            candidate.append(q)

    i = rd.randint(0, len(candidate) - 1)  # Select randomly an index
    select_queen = candidate[i]
    return select_queen

def GetDelta(q, r):
    # Return the change of the number of violations if queen q is moved to row r
    current_row = x[q]
    x[q] = r  # Temporarily move the queen q to the row r
    new_violations = Violations()  # Compute new violations with the new position of queen q
    delta = new_violations - violations
    x[q] = current_row  # Restore the current row of the queen q
    return delta

def SelectMostPromissingRow(q):
    min_delta = 100000
    selected_row = -1
    candidate = []
    for r in range(n):
        delta = GetDelta(q, r)
        if delta < min_delta:
            min_delta = delta
            candidate = []
            candidate.append(r)
        elif delta == min_delta:
            candidate.append(r)

    i = rd.randint(0, len(candidate) - 1)
    selected_row = candidate[i]
    return selected_row

def LocalSearch(maxIter):
    global violations
    for it in range(maxIter):
        q = SelectMostViolatingQueen()
        r = SelectMostPromissingRow(q)
        x[q] = r
        print(f"Current step {it}:", x)
        violations = Violations()
        print('Step', it, 'violations =', violations)
        if violations == 0:
            print('FOUND')
            break

# Initialize parameters
n = 5
x = [0 for i in range(n)]  # Current solution x[i] is the row of the queen on column i (i = 0, ..., n-1)
print(x)
violations = Violations()  # (Global) store the violations of the current solution

# Perform local search
LocalSearch(1000)
