from ortools.linear_solver.pywraplp import Solver

def balanced_course_assignment():
    # Input
    m, n = map(int, input().split())
    preferences = []
    for _ in range(m):
        line = list(map(int, input().split()))
        preferences.append(set(line[1:]))

    k = int(input())
    conflicts = []
    for _ in range(k):
        i, j = map(int, input().split())
        conflicts.append((i - 1, j - 1))  # 0-based index

    # Model
    solver = Solver.CreateSolver("CBC")

    # Variables
    x = [[solver.BoolVar(f"x[{i},{j}]") for j in range(n)] for i in range(m)]
    L = solver.IntVar(0, n, "L")  # Tải trọng tối đa

    # Constraints
    # 1. Mỗi khóa học được phân bổ đúng một giáo viên
    for j in range(n):
        solver.Add(sum(x[i][j] for i in range(m)) == 1)

    # 2. Tuân theo danh sách sở thích
    for i in range(m):
        for j in range(n):
            if j + 1 not in preferences[i]:  # Khóa học j không nằm trong sở thích của giáo viên i
                solver.Add(x[i][j] == 0)

    # 3. Không có xung đột
    for i in range(m):
        for j1, j2 in conflicts:
            solver.Add(x[i][j1] + x[i][j2] <= 1)

    # 4. Tải trọng tối đa
    for i in range(m):
        solver.Add(sum(x[i][j] for j in range(n)) <= L)

    # Objective
    solver.Minimize(L)

    # Solver
    status = solver.Solve()

    # Output
    if status == Solver.OPTIMAL:
        print(int(L.solution_value()))
    else:
        print(-1)

# Run the function
balanced_course_assignment()
