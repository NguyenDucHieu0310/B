from ortools.sat.python import cp_model
import sys

def input():
    [n,m] = [int(x) for x in sys.stdin.readline().split()]
    A = {}
    B = {}
    for i in range(1,n+1):
        A[i] = []

    for i in range (m):
        [u,v,c] = [int(x) for x in sys.stdin.readline().split()]
        A[u].append([v,c])
        B[v].append([u,c])

    return n,m,A,B

def input_file(filename):
    with open(filename) as f:
        n, m = map(int, f.readline().split())
        A = {i: [] for i in range(1, n+1)}
        B = {i: [] for i in range(1, n+1)}
        
        for _ in range(m):
            u, v, c = map(int, f.readline().split())
            A[u].append([v, c])
            B[v].append([u, c])

    return n,m,A,B

n,m,A,B = input_file("../input.txt")
#variables
model = cp_model.CpModel()
x = {} #x[i,j]=1 mean that node i sends to node j in path 1
y = {} #y[i,j]=1 mean that node i sends to node j in path 2

for i in range(1, n+1):
    for [j,c] in A[i]:
        x[i,j] = model.NewIntVar(0,1,'x(' + str(i) + ',' + str(j) + ')')
        y[i,j] = model.NewIntVar(0,1,'y(' + str(i) + ',' + str(j) + ')')

obj = model.NewIntVar(0,10000,'obj')

#constraints
for i in range(1, n+1):
    for [j,c] in A[i]:
        path_1 = model.NewBoolVar('')
        path_2 = model.NewBoolVar('')
        model.Add(x[i,j] == 1).OnlyEnforceIf(path_1)
        model.Add(x[i,j] == 0).OnlyEnforceIf(path_1.Not())
        model.Add(y[i,j] == 1).OnlyEnforceIf(path_2)
        model.Add(y[i,j] == 0).OnlyEnforceIf(path_2.Not())

        model.Add(x[i,j] + y[i,j] <= 1)

#constrain start in 0 and end in n-1
for i in range(1,n+1):
    if i == 1:
        for [j,c] in B[i]:
            model.Add(x[j,i] == 0)
            model.Add(y[j,i] == 0)

        model.Add(sum(x[i,j] for [j,c] in A[i]) == 1)
        model.Add(sum(y[i,j] for [j,c] in A[i]) == 1)

    elif i == n:
        for [j,c] in A[i]:
            model.Add(x[i,j] == 0)
            model.Add(y[i,j] == 0)

        model.Add(sum(x[j,i] for [j,c] in B[i]) == 1)
        model.Add(sum(y[j,i] for [j,c] in B[i]) == 1)

    else:
        model.Add(sum(x[j,i] for [j,c] in B[i]) == sum(x[i,j] for [j,c] in A[i]))
        model.Add(sum(y[j,i] for [j,c] in B[i]) == sum(y[i,j] for [j,c] in A[i]))

#objective
model.Add(obj == sum(c*(x[i,j] + y[i,j]) for i in range(1,n+1) for [j,c] in A[i]))
model.Minimize(obj)

#solve
solver = cp_model.CpSolver()
status = solver.Solve(model)

if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
    print(solver.Value(obj))
else:
    print('NOT_FEASIBLE')

