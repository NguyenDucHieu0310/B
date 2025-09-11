from ortools.sat.python import cp_model
import sys

# Read input from stdin
input_data = sys.stdin.read().strip().splitlines()

max_int = 10000

# Parse the first line for n, m, s, l
n, m, s, l = map(int, input_data[0].split())
edges = [list(map(int, input_data[i].split())) for i in range(1, m + 1)]

# Create adjacency list with weights and costs
A = {i: [] for i in range(1, n + 1)}
for u, v, t, c in edges:
    A[u].append((v, t, c))
    A[v].append((u, t, c))

model = cp_model.CpModel()

# Create variables for edges and time received at each node
x = {}  # x[i, j] = 1 means node i sends data to node j
y = {}  # time-point when node i receives data

for i in range(1, n + 1):
    for j, t, c in A[i]:
        x[i, j] = model.NewBoolVar(f'x({i}, {j})')

for i in range(1, n + 1):
    y[i] = model.NewIntVar(0, max_int, f'y({i})')

# Objective variable
obj = model.NewIntVar(0, max_int, 'obj')

# Add constraints
for i in range(1, n + 1):
    for j, t, c in A[i]:
        model.Add(y[j] == y[i] + t).OnlyEnforceIf(x[i, j])
    model.Add(y[i] <= l)  # Ensure each node receives data within time limit

# Set time for source node to 0
model.Add(y[s] == 0)

# Each node (except the source) must receive data from exactly one incoming link
for j in range(1, n + 1):
    if j != s:
        model.Add(sum(x[i, j] for i, t, c in A[j]) == 1)

# Define the total cost objective
model.Add(obj == sum(x[i, j] * c for i in range(1, n + 1) for j, t, c in A[i]))
model.Minimize(obj)

# Solve the model
solver = cp_model.CpSolver()
solver.parameters.max_time_in_seconds = 10.0
status = solver.Solve(model)

if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
    print(solver.Value(obj))
else:
    print('NO SOLUTION')