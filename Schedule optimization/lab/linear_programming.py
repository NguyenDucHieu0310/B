from ortools.linear_solver import pywraplp

def solve_linear_program(n, m, lower_bounds, upper_bounds, C, A, lows, ups):
    # Khởi tạo solver
    solver = pywraplp.Solver.CreateSolver('GLOP')
    if not solver:
        print("Solver not found.")
        return
    
    # Tạo các biến quyết định X[i] với ràng buộc DL[i] <= X[i] <= DU[i]
    X = []
    for i in range(n):
        X.append(solver.NumVar(lower_bounds[i], upper_bounds[i], f'X[{i}]'))
    
    # Thiết lập hàm mục tiêu: maximize C[1]*X[1] + C[2]*X[2] + ... + C[n]*X[n]
    objective = solver.Objective()
    for i in range(n):
        objective.SetCoefficient(X[i], C[i])
    objective.SetMaximization()

    # Thêm ràng buộc tuyến tính cho từng hàng của ma trận A
    for i in range(m):
        constraint = solver.Constraint(lows[i], ups[i])
        for j in range(n):
            constraint.SetCoefficient(X[j], A[i][j])

    # Giải bài toán
    status = solver.Solve()

    if status == pywraplp.Solver.OPTIMAL:
        # In kết quả nếu tìm thấy lời giải tối ưu
        print(n)
        result = [X[i].solution_value() for i in range(n)]
        print(" ".join(map(str, result)))
    else:
        # Nếu không có lời giải tối ưu
        print("NOT_OPTIMAL")


def main():
    # Nhập dữ liệu từ input()
    n, m = map(int, input().split())

    # Nhập DL và DU
    lower_bounds = []
    upper_bounds = []
    for _ in range(n):
        DL, DU = map(int, input().split())
        lower_bounds.append(DL)
        upper_bounds.append(DU)

    # Nhập vector C
    C = list(map(int, input().split()))

    # Nhập ma trận A
    A = []
    for _ in range(m):
        row = list(map(int, input().split()))
        A.append(row)

    # Nhập low và up
    lows = []
    ups = []
    for _ in range(m):
        low, up = map(int, input().split())
        lows.append(low)
        ups.append(up)

    # Giải bài toán
    solve_linear_program(n, m, lower_bounds, upper_bounds, C, A, lows, ups)


if __name__ == "__main__":
    main()
