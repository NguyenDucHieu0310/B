from ortools.linear_solver import pywraplp
import sys

def main():
    # Đọc dữ liệu đầu vào
    data = sys.stdin.read().split()
    n = int(data[0])
    c = [[0]*n for _ in range(n)]
    index = 1
    for i in range(n):
        for j in range(n):
            c[i][j] = int(data[index])
            index +=1

    solver = pywraplp.Solver.CreateSolver('CBC')
    if not solver:
        print('Solver not found.')
        return

    # Tạo biến quyết định x[i][j]
    x = {}
    for i in range(n):
        for j in range(n):
            if i != j:
                x[i, j] = solver.BoolVar(f'x[{i},{j}]')

    # Ràng buộc: Từ mỗi thành phố phải đi đến đúng một thành phố khác
    for i in range(n):
        solver.Add(solver.Sum([x[i, j] for j in range(n) if i != j]) == 1)

    # Ràng buộc: Đến mỗi thành phố phải từ một thành phố khác
    for j in range(n):
        solver.Add(solver.Sum([x[i, j] for i in range(n) if i != j]) == 1)

    # Biến phụ u[i] cho MTZ subtour elimination
    u = {}
    for i in range(1, n):
        u[i] = solver.NumVar(1, n - 1, f'u[{i}]')

    # Ràng buộc MTZ subtour elimination
    for i in range(1, n):
        for j in range(1, n):
            if i != j:
                solver.Add(u[i] - u[j] + (n - 1)*x[i, j] <= n - 2)

    # Hàm mục tiêu: Tối thiểu hóa tổng chi phí
    solver.Minimize(solver.Sum([c[i][j]*x[i, j] for i in range(n) for j in range(n) if i != j]))

    status = solver.Solve()

    if status == pywraplp.Solver.OPTIMAL:
        # In ra kết quả
        print(n)
        # Xây dựng tour
        tour = [0]
        current_city = 0
        while len(tour) < n:
            for j in range(n):
                if current_city != j and x[current_city, j].solution_value() > 0.5:
                    tour.append(j)
                    current_city = j
                    break
        # Chuyển chỉ số thành phố từ 0-based sang 1-based
        tour = [city + 1 for city in tour]
        print(' '.join(map(str, tour)))
    else:
        print('No solution found.')

if __name__ == '__main__':
    main()
