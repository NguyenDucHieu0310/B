from ortools.linear_solver import pywraplp
import sys

def solve():
    input = sys.stdin.read
    data = input().splitlines()
    
    n, m = map(int, data[0].split())
    edges = []
    for i in range(1, m + 1):
        u, v, c = map(int, data[i].split())
        edges.append((u, v, c))
    
    solver = pywraplp.Solver.CreateSolver('CBC')
    if not solver:
        print("NOT_FEASIBLE")
        return
    
    # Variables
    x = {}
    y = {}
    for u, v, c in edges:
        x[u, v] = solver.BoolVar(f"x[{u},{v}]")
        y[u, v] = solver.BoolVar(f"y[{u},{v}]")
    
    # Constraints for edge-disjoint paths
    for u, v, c in edges:
        solver.Add(x[u, v] + y[u, v] <= 1)
    
    # Flow constraints for path 1
    for k in range(1, n + 1):
        if k == 1:
            solver.Add(solver.Sum(x[u, v] for u, v, _ in edges if u == k) - 
                       solver.Sum(x[u, v] for u, v, _ in edges if v == k) == 1)
        elif k == n:
            solver.Add(solver.Sum(x[u, v] for u, v, _ in edges if v == k) - 
                       solver.Sum(x[u, v] for u, v, _ in edges if u == k) == 1)
        else:
            solver.Add(solver.Sum(x[u, v] for u, v, _ in edges if u == k) - 
                       solver.Sum(x[u, v] for u, v, _ in edges if v == k) == 0)
    
    # Flow constraints for path 2
    for k in range(1, n + 1):
        if k == 1:
            solver.Add(solver.Sum(y[u, v] for u, v, _ in edges if u == k) - 
                       solver.Sum(y[u, v] for u, v, _ in edges if v == k) == 1)
        elif k == n:
            solver.Add(solver.Sum(y[u, v] for u, v, _ in edges if v == k) - 
                       solver.Sum(y[u, v] for u, v, _ in edges if u == k) == 1)
        else:
            solver.Add(solver.Sum(y[u, v] for u, v, _ in edges if u == k) - 
                       solver.Sum(y[u, v] for u, v, _ in edges if v == k) == 0)
    
    # Objective function: minimize the sum of lengths
    solver.Minimize(solver.Sum(x[u, v] * c for u, v, c in edges) +
                    solver.Sum(y[u, v] * c for u, v, c in edges))
    
    # Solve the problem
    status = solver.Solve()
    if status == pywraplp.Solver.OPTIMAL:
        print(int(solver.Objective().Value()))
    else:
        print("NOT_FEASIBLE")

if __name__ == "__main__":
    solve()
