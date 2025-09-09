from ortools.sat.python import cp_model
import sys

def input():
    [n] = [int(x) for x in sys.stdin.readline().split()]
    A = []
    for i in range(n):
        c = [int(x) for x in sys.stdin.readline().split()]
        A.append(c)
    return n, A

def input_file(file_path):
    with open(file_path, 'r') as file:
        n = int(file.readline())
        A = []
        for i in range(n):
            c = [int(x) for x in file.readline().split()]
            A.append(c)
        return n, A
    

# n, X = input_file('../input.txt')

# # create solver
# model = cp_model.CpModel()

# # define decision variables
# # X[i][j] = 1 if the salesman goes from city i to city j
# X = [[model.NewIntVar(0, 1, 'x(' + str(i) + ',' + str(j) + ')') for j in range(n)] for i in range(n)]
# Y = [model.NewIntVar(0, n-1, 'y(' + str(i) + ')') for i in range(n)]

# #Y is difff
# model.AddAllDifferent(Y)
# model.Add(Y[0] == 0)

# for i in range(n):
#     model.Add(sum(X[i][j] for j in range(n)) == 1)  # Each city is visited exactly once
#     model.Add(sum(X[j][i] for j in range(n)) == 1)  # From each city, there is exactly one way out

# # Tạo biến đại diện cho tổng chi phí hành trình
# total_cost = model.NewIntVar(0, 1000, 'total_cost')

# # Xây dựng hàm chi phí
# for i in range(n):
#     for j in range(n):
#         model.Add(X[i][j] == 0).OnlyEnforceIf(Y[i] == Y[j])
#         model.Add(X[i][j] == 1).OnlyEnforceIf(Y[i] == Y[j] + 1)
def tsp_cp_solver_fixed_output(n, A):
    # Create the model
    model = cp_model.CpModel()

    # Decision variables: next[i] indicates the city visited after city i
    next_city = [model.NewIntVar(0, n - 1, f'next({i})') for i in range(n)]
    
    # Variables to represent the order of visits
    order = [model.NewIntVar(0, n - 1, f'order({i})') for i in range(n)]

    # Create Boolean variables to indicate transitions
    transitions = [
        [model.NewBoolVar(f'transition({i},{j})') for j in range(n)]
        for i in range(n)
    ]

    # Constraints
    # 1. Each city must be visited exactly once
    for i in range(n):
        model.Add(sum(transitions[i][j] for j in range(n) if i != j) == 1)  # Row constraints
        model.Add(sum(transitions[j][i] for j in range(n) if i != j) == 1)  # Column constraints

    # 2. Link transitions with next_city variables
    for i in range(n):
        for j in range(n):
            if i != j:
                model.Add(next_city[i] == j).OnlyEnforceIf(transitions[i][j])
                model.Add(next_city[i] != j).OnlyEnforceIf(transitions[i][j].Not())

    # 3. Subtour elimination using order variables
    for i in range(1, n):  # Start from 1 because the first city is the start
        for j in range(1, n):
            if i != j:
                model.Add(order[i] < order[j]).OnlyEnforceIf(transitions[i][j])

    # Objective: Minimize the total cost
    total_cost = model.NewIntVar(0, sum(sum(row) for row in A), 'total_cost')
    model.Add(total_cost == sum(A[i][j] * transitions[i][j] for i in range(n) for j in range(n)))
    model.Minimize(total_cost)

    # Solve the model
    solver = cp_model.CpSolver()
    status = solver.Solve(model)

    # Output results
    if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
        tour = []
        current = 0
        for _ in range(n):
            tour.append(current + 1)  # Convert to 1-based index
            for j in range(n):
                if solver.Value(transitions[current][j]) == 1:
                    current = j
                    break
        print(n)
        print(" ".join(map(str, tour)))
    else:
        print("No solution found.")

# Example usage
if __name__ == "__main__":
    # Example adjacency matrix
    n, A = input_file('../input.txt')  # Input file path
    tsp_cp_solver_fixed_output(n, A)