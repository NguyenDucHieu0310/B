def calculate_violations(N, x, actions):
    constraints = []  # Store constraints
    results = []  # Store results for "violations"

    def count_violations():
        violations = 0
        for c in constraints:
            if c[0] == "AllDifferent":
                for i in range(N):
                    for j in range(i + 1, N):
                        if x[i] == x[j]:
                            violations += 1
            elif c[0] == "IsEqual":
                i, j = c[1], c[2]
                violations += abs(x[i - 1] - x[j - 1])
            elif c[0] == "LessThanEqual":
                i, j = c[1], c[2]
                violations += max(0, x[i - 1] - x[j - 1])
        return violations

    for action in actions:
        parts = action.split()
        if parts[0] == "post":
            if parts[1] == "AllDifferent":
                constraints.append(("AllDifferent",))
            elif parts[1] == "IsEqual":
                i, j = int(parts[2]), int(parts[3])
                constraints.append(("IsEqual", i, j))
            elif parts[1] == "LessThanEqual":
                i, j = int(parts[2]), int(parts[3])
                constraints.append(("LessThanEqual", i, j))
        elif parts[0] == "update":
            i, v = int(parts[1]), int(parts[2])
            x[i - 1] = v
        elif parts[0] == "violations":
            results.append(count_violations())

    return results


def main():
    N = int(input())
    x = list(map(int, input().split()))
    actions = []
    while True:
        action = input()
        if action == "#":
            break
        actions.append(action)
    
    results = calculate_violations(N, x, actions)
    for res in results:
        print(res)


if __name__ == "__main__":
    main()
