from ortools.linear_solver.pywraplp import Solver

def input_data():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    C = [0]*n
    for i in range(n):
        C[i] = list(map(int, input().split()))

    return n, m, A, B, C

def main():
    n, m, A, B, C = input_data()

    solver = Solver.CreateSolver('GLOP')

    T = {}
    infinity = Solver.infinity()
    for i in range(n):
        for j in range(m):
            T[i, j] = solver.NumVar(0, infinity, f'T[i, j]')

    for i in range(n):
        solver.Add(sum(T[i, j] for j in range(m)) <= A[i])
    
    for j in range(m):
        solver.Add(sum(T[i, j] for i in range(n)) >= B[j])

    solver.Minimize(sum(T[i, j]*C[i][j] for j in range(m) for i in range(n)))

    status = solver.Solve()

    if status == Solver.OPTIMAL:
        edges = []
        for i in range(n):
            for j in range(m):
                if T[i, j].solution_value() > 0:
                    edges.append([i, j, T[i, j].solution_value()])

        # print(solver.Objective().Value())

        print(len(edges))
        for edge in edges:
            print(edge[0]+1, edge[1]+1, edge[2])
    else:
        print(status)

if __name__ == '__main__':
    main()