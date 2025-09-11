from ortools.sat.python import cp_model

def create_data_model():
    """Đọc dữ liệu từ input"""
    m, n = map(int, input().split())  # Số giáo viên và số khóa học
    preferences = []
    
    # Đọc danh sách khóa học mà mỗi giáo viên có thể dạy
    for _ in range(m):
        pref = list(map(int, input().split()))[1:]  # Bỏ qua số lượng và chỉ lấy danh sách khóa học
        preferences.append(pref)
    
    # Đọc danh sách các khóa học xung đột
    k = int(input())
    conflicts = []
    for _ in range(k):
        i, j = map(int, input().split())
        conflicts.append((i - 1, j - 1))  # Giảm index để dùng 0-based index

    data = {
        'm': m,
        'n': n,
        'preferences': preferences,
        'conflicts': conflicts
    }
    return data

def solve_balanced_course_assignment(data):
    model = cp_model.CpModel()

    m = data['m']  # Số giáo viên
    n = data['n']  # Số khóa học
    preferences = data['preferences']
    conflicts = data['conflicts']

    # Tạo biến quyết định x[t][c]: x[t][c] = 1 nếu giáo viên t dạy khóa học c
    x = {}
    for t in range(m):
        for c in range(n):
            x[(t, c)] = model.NewBoolVar(f'x[{t},{c}]')

    # Tạo biến max_load để theo dõi tải lớn nhất giữa các giáo viên
    max_load = model.NewIntVar(0, n, 'max_load')

    # Ràng buộc: Mỗi khóa học chỉ được giao cho một giáo viên
    for c in range(n):
        model.Add(sum(x[t, c] for t in range(m) if c + 1 in preferences[t]) == 1)

    # Ràng buộc: Các khóa học xung đột không thể được giao cho cùng một giáo viên
    for (i, j) in conflicts:
        for t in range(m):
            model.Add(x[t, i] + x[t, j] <= 1)

    # Ràng buộc: Tính tải của mỗi giáo viên
    for t in range(m):
        load = sum(x[t, c] for c in range(n) if c + 1 in preferences[t])
        model.Add(load <= max_load)

    # Mục tiêu: Tối thiểu hóa tải lớn nhất giữa các giáo viên
    model.Minimize(max_load)

    # Khởi tạo bộ giải
    solver = cp_model.CpSolver()
    status = solver.Solve(model)

    if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
        print(solver.Value(max_load))
    else:
        print(-1)

def main():
    # Đọc dữ liệu
    data = create_data_model()

    # Giải bài toán
    solve_balanced_course_assignment(data)

if __name__ == '__main__':
    main()
