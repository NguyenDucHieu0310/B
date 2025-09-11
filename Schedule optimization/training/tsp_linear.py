from ortools.linear_solver.pywraplp import Solver
import sys

def solve():
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    c = [[0]*n for _ in range(n)]
    idx = 1
    for i in range(n):
        for j in range(n):
            c[i][j] = data[idx]
            idx += 1

    solver = Solver.CreateSolver('CBC')
    if not solver:
        print('Solver not found.')
        return

    # Khai báo các biến quyết định
    x = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i != j:
                x[i][j] = solver.BoolVar(f"x[{i}, {j}]")

    # Ràng buộc: mỗi thành phố có một chuyến đi đến và từ
    for i in range(n):
        solver.Add(solver.Sum([x[i][j] for j in range(n) if j != i]) == 1)
    for i in range(n):
        solver.Add(solver.Sum([x[j][i] for j in range(n) if j != i]) == 1)

    # Biến phụ u[i] cho loại bỏ chu kỳ con (subtour elimination)
    u = [None]*n
    for i in range(1, n):
        u[i] = solver.NumVar(1, n - 1, f"u[{i}]")

    # Ràng buộc loại bỏ chu kỳ con MTZ
    for i in range(1, n):
        for j in range(1, n):
            if i != j:
                solver.Add(u[i] - u[j] + (n - 1) * x[i][j] <= n - 2)

    # Hàm mục tiêu: tối thiểu hóa tổng chi phí
    solver.Minimize(solver.Sum([x[i][j] * c[i][j] for i in range(n) for j in range(n) if i != j]))

    status = solver.Solve()
    if status == Solver.OPTIMAL:
        u_value = [u[i].solution_value() for i in range(1, n)]
        argmin_u = sorted(range(2, n+1), key=lambda i: u_value[i-2])
        line = " ".join(f"{x}" for x in argmin_u)
        print(n)
        print(1, line)
    else:
        print('No solution')

if __name__ == "__main__":
    solve()
