from ortools.linear_solver import pywraplp

def input_data():
    n, m = map(int, input().split())
    DL, DU = [0]*(n+1), [0]*(n+1)
    C = [0]*(n+1)
    A = [[0]*(n+1) for _ in range(m+1)]
    low, up = [0]*(m+1), [0]*(m+1)

    for i in range(1, n+1):
        DL[i], DU[i] = map(int, input().split())
    
    C[1:] = C[1:] = list(map(int, input().split()))

    for i in range(1, m+1):
        A[i][1:] = list(map(int, input().split()))

    for i in range(1, m+1):
        low[i], up[i] = map(int, input().split())

    return n, m, DL, DU, C, A, low, up

def solve():
    n, m, DL, DU, C, A, low, up = input_data()

    solver = pywraplp.Solver.CreateSolver('GLOP')
    if not solver:
        print("Solver not created")
        return


    x = [0]*(n+1)
    for i in range(1, n+1):
        x[i] = solver.NumVar(DL[i], DU[i], f"x[{i}]")

    for i in range(1, m+1):
        ct = solver.Constraint(low[i], up[i], f"ct {i}th")
        for j in range(1, n+1):
            ct.SetCoefficient(x[j], A[i][j])

    obj = solver.Objective()
    for i in range(1, n+1):
        obj.SetCoefficient(x[i], C[i])

    obj.SetMaximization()

    status = solver.Solve()

    if status == pywraplp.Solver.OPTIMAL:
        line = " ".join([f"{x[i].solution_value()}" for i in range(1, n+1)])
        print(n)
        print(line)
    else:
        print("NOT_OPTIMAL")

if __name__ == "__main__":
    solve()

        
            