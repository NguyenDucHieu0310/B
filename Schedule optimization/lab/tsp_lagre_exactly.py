from ortools.linear_solver import pywraplp

def create_data_model_from_file(filename):
    """Đọc dữ liệu từ file .txt"""
    with open(filename, 'r') as file:
        lines = file.readlines()
    
    n = int(lines[0].strip())  # Số lượng thành phố
    distance_matrix = []
    for line in lines[1:n+1]:
        row = list(map(int, line.split()))
        distance_matrix.append(row)
    
    return {
        'distance_matrix': distance_matrix,
        'n': n
    }

def create_data_model():
    """Đọc dữ liệu từ stdin"""
    n = int(input())  # Số thành phố
    distance_matrix = []
    for _ in range(n):
        row = list(map(int, input().split()))
        distance_matrix.append(row)
    
    return {
        'distance_matrix': distance_matrix,
        'n': n
    }

def tsp_mip():
    data = create_data_model_from_file('input.txt')
    n = data['n']
    dist = data['distance_matrix']

    # Khởi tạo solver MIP
    solver = pywraplp.Solver.CreateSolver('SCIP')
    
    # Biến quyết định x[i][j]: 1 nếu đi từ thành phố i đến thành phố j, ngược lại là 0
    x = {}
    for i in range(n):
        for j in range(n):
            if i != j:
                x[i, j] = solver.BoolVar(f'x[{i},{j}]')
    
    # Ràng buộc: Mỗi thành phố phải có đúng một cạnh đi ra
    for i in range(n):
        solver.Add(sum(x[i, j] for j in range(n) if i != j) == 1)

    # Ràng buộc: Mỗi thành phố phải có đúng một cạnh đi vào
    for j in range(n):
        solver.Add(sum(x[i, j] for i in range(n) if i != j) == 1)
    
    # Hàm mục tiêu: tối thiểu hóa tổng khoảng cách
    solver.Minimize(solver.Sum(x[i, j] * dist[i][j] for i in range(n) for j in range(n) if i != j))

    # Ràng buộc loại bỏ chu trình con (Subtour elimination)
    u = {}
    for i in range(1, n):
        u[i] = solver.IntVar(0, n - 1, f'u[{i}]')

    for i in range(1, n):
        for j in range(1, n):
            if i != j:
                solver.Add(u[i] - u[j] + (n - 1) * x[i, j] <= n - 2)

    # Giải bài toán
    status = solver.Solve()

    if status == pywraplp.Solver.OPTIMAL:
        print(n)
        # Truy xuất lời giải
        current_city = 0
        tour = [1]  # Bắt đầu từ thành phố 1 (index = 0)
        for _ in range(n - 1):
            for j in range(n):
                if current_city != j and x[current_city, j].solution_value() > 0.5:
                    tour.append(j + 1)
                    current_city = j
                    break
        print(" ".join(map(str, tour)))
    else:
        print("No solution found.")

if __name__ == '__main__':
    tsp_mip()