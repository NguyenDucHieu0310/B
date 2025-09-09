from ortools.linear_solver import pywraplp
import sys

def input():
    [n,m] = [int(x) for x in sys.stdin.readline().split()]
    DL = []
    DU = []
    for i in range(1, n+1):
        [dl,du] = [int(x) for x in sys.stdin.readline().split()]
        DL.append(dl)
        DU.append(du)
    
    C = []
    for i in range(1,n+1):
        c = [int(x) for x in sys.stdin.readline().split()]
        C.append(c)

    A = {}
    for i in range(1,n+1):
        A[i] = []
    for i in range(1,m+1):
        a = [int(x) for x in sys.stdin.readline().split()]
        for j in range(1,n+1):
            A[i].append(a[j-1])

    low = []
    up = []
    for i in range(1,m+1):
        [l,u] = [int(x) for x in sys.stdin.readline().split()]
        low.append(l)
        up.append(u)

    return n,m,DL,DU,C,A,low,up

def input_file(filename):
    with open(filename, "r") as f:
        [n, m] = [int(x) for x in f.readline().split()]
        print("n,m", n, m)
        DL = []
        DU = []
        for i in range(1, n + 1):
            [dl, du] = [int(x) for x in f.readline().split()]
            print("dl,du", dl, du)
            DL.append(dl)
            DU.append(du)

        C = []
        c = [int(x) for x in f.readline().split()]
        print("c", c)
        C.append(c)

        A = {}
        for i in range(1, n + 1):
            A[i] = []
        for i in range(1, m + 1):
            a = [int(x) for x in f.readline().split()]
            print(a)
            for j in range(1, n + 1):
                A[j].append(a[j - 1])

        low = []
        up = []
        for i in range(1, m + 1):
            [l, u] = [int(x) for x in f.readline().split()]
            low.append(l)
            up.append(u)

    return n, m, DL, DU, C, A, low, up

n, m, DL, DU, C, A, low, up = input_file("../input.txt")
print("n", n)
print("m", m)
print("DL", DL)
print("DU", DU)
print("C", C)
print("A", A)
print("low", low)
print("up", up)

solver = pywraplp.Solver.CreateSolver('GLOP')

X = []

for i in range(1, n + 1):
    X.append(solver.NumVar(DL[i - 1], DU[i - 1], f'X[{i}]'))

for i in range(1, m + 1):
    sum = solver.Sum([A[j][i - 1] * X[j - 1] for j in range(1, n + 1)])

    if low[i - 1] != -100000:
        solver.Add(sum >= low[i - 1])
    if up[i - 1] != 100000:
        solver.Add(sum <= up[i - 1])

objective = solver.Objective()
for i in range(1, n + 1):
    objective.SetCoefficient(X[i - 1], C[0][i - 1])

objective.SetMaximization()

solver.Solve()
print(solver.Objective().Value())
print([X[i].solution_value() for i in range(n)])