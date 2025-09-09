from ortools.sat.python import cp_model
import sys
def input():
    [n] = [int(x) for x in sys.stdin.readline().split()]

    return n

n = input()

# create solver
model = cp_model.CpModel()

# define decision variables x in [0,n-1]
x = [model.NewIntVar(0, n-1, 'x(' + str(i) + ')') for i in range(n)]

#constraint
model.AddAllDifferent(x)

for i in range(n):
    for j in range(n):
        if i != j:
            model.Add((i-j) != (x[i] - x[j]))
            model.Add((i-j) != (x[j] - x[i]))

#solver
solver = cp_model.CpSolver()
#set time
solver.parameters.max_time_in_seconds = 5.0
#solve
status = solver.Solve(model)


if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
    print(' '.join([str(solver.Value(x[i])) for i in range(n)]))
else:
    print('No solution found')  

