from ortools.linear_solver.pywraplp import Solver

def input_data():
    n, m = map(int, input().split())
    
    A = [0]*m
    for i in range(m):
        A[i] = list(map(int, input().split()))[1:]
        
    k = int(input())
    B = [0]*k
    
    for i in range(k):
        a, b = map(lambda x: int(x) - 1, input().split())
        B[i] = (a, b)
    
    return n, m, A, B
    
def main():
    n, m, A, B = input_data()
    
    solver = Solver.CreateSolver('SCIP')
    
    x = [[0]*m for i in range(n)]
    
    for i in range(n):
        for j in range(m):
                x[i][j] = solver.BoolVar(f'x[{i}][{j}]')
            
    for i in range(n):
        for j in range(m):
            if i not in B[j]:
                x[i][j] = solver.Add(x[i][j] == 0)
                
    for i in range(n):
        solver.Add(sum(x[i][j] for j in range(m)) == 1)
        
    for a, b in B:
        for j in range(m):
            solver.Add(x[a][j] + x[b][j] <= 1)
        
    Obj = solver.IntVar(0, n, "Obj")
    for j in range(m):
        solver.Add(sum(x[i][j] for i in range(n)) <= Obj)
        
    solver.Minimize(Obj)
        
    status = solver.Solve()
    
    if status == Solver.OPTIMAL:
        print(solver.Objective().Value())
    else:
        print(-1)
        
main()