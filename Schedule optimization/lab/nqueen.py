import random
import time

# Hàm tính số cặp quân hậu tấn công nhau
def count_conflicts(x, n):
    row_conflicts = [0] * n
    diag1_conflicts = [0] * (2 * n - 1)
    diag2_conflicts = [0] * (2 * n - 1)

    conflicts = 0
    for i in range(n):
        row_conflicts[x[i]] += 1
        diag1_conflicts[i - x[i] + n - 1] += 1
        diag2_conflicts[i + x[i]] += 1

    for i in range(n):
        if row_conflicts[x[i]] > 1:
            conflicts += row_conflicts[x[i]] - 1
        if diag1_conflicts[i - x[i] + n - 1] > 1:
            conflicts += diag1_conflicts[i - x[i] + n - 1] - 1
        if diag2_conflicts[i + x[i]] > 1:
            conflicts += diag2_conflicts[i + x[i]] - 1

    return conflicts

# Hàm sinh một lời giải ngẫu nhiên
def random_solution(n):
    return [random.randint(0, n - 1) for _ in range(n)]

# Hàm tìm kiếm cục bộ sử dụng Hill Climbing với Random Restart
def solve_n_queens(n, time_limit):
    start_time = time.time()  # Lưu thời gian bắt đầu
    best_solution = random_solution(n)
    best_conflicts = count_conflicts(best_solution, n)

    # Vòng lặp chính, dừng lại nếu vượt quá giới hạn thời gian
    while time.time() - start_time < time_limit:
        current_solution = random_solution(n)
        current_conflicts = count_conflicts(current_solution, n)

        while current_conflicts != 0 and time.time() - start_time < time_limit:
            col = random.randint(0, n - 1)
            best_row = current_solution[col]
            best_col_conflicts = current_conflicts

            for row in range(n):
                if row != current_solution[col]:
                    new_solution = current_solution[:]
                    new_solution[col] = row
                    new_conflicts = count_conflicts(new_solution, n)

                    if new_conflicts < best_col_conflicts:
                        best_row = row
                        best_col_conflicts = new_conflicts

            current_solution[col] = best_row
            current_conflicts = best_col_conflicts

            if current_conflicts == 0:
                break

        # Cập nhật nếu lời giải tốt hơn
        if current_conflicts < best_conflicts:
            best_solution = current_solution[:]
            best_conflicts = current_conflicts

        # Nếu tìm được lời giải hoàn hảo (0 xung đột), trả về ngay
        if best_conflicts == 0:
            break

    return best_solution

# Đọc input
n = int(input())

# Thời gian tối đa cho phép chạy (25 giây)
time_limit = 25

# Tìm lời giải cho bài toán N-Queens trong giới hạn thời gian
solution = solve_n_queens(n, time_limit)

# In kết quả
print(n)
print(' '.join(str(x + 1) for x in solution))
