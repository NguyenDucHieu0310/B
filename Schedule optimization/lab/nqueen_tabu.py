import random as rd

n = 30
x = [0] * n  # x[i] là hàng của quân hậu tại cột i
T = [[0] * n for i in range(n)]  # T[q][r] > 0 nghĩa là di chuyển quân hậu q đến hàng r bị cấm tại thời điểm hiện tại

tbl = 50  # Thời hạn của tabu

def get_violations():
    v = 0
    for i in range(n):
        for j in range(i + 1, n):
            if x[i] == x[j] or x[i] + i == x[j] + j or x[i] - i == x[j] - j:
                v += 1
    return v

def get_delta(q, r):
    delta = 0
    current_row = x[q]
    
    # Đếm xung đột hiện tại của quân hậu q
    for i in range(n):
        if i != q:
            if x[i] == current_row or x[i] + i == current_row + q or x[i] - i == current_row - q:
                delta -= 1  # Giảm xung đột của hàng hiện tại
    
    # Đếm xung đột nếu quân hậu q di chuyển đến hàng r
    for i in range(n):
        if i != q:
            if x[i] == r or x[i] + i == r + q or x[i] - i == r - q:
                delta += 1  # Tăng xung đột của hàng mới

    return delta

def gen_initial_solution():
    for i in range(n):
        x[i] = i
    rd.shuffle(x)  # Hoán vị ngẫu nhiên để khởi tạo lời giải ban đầu

def tabu_select(it):
    min_delta = float('inf')
    L = []  # Danh sách các nước đi tốt nhất

    # Tìm nước đi tốt nhất không thuộc danh sách tabu
    for q in range(n):
        for r in range(n):
            if x[q] != r and T[q][r] <= it:
                delta = get_delta(q, r)
                if delta < min_delta:
                    min_delta = delta
                    L = [(q, r)]
                elif delta == min_delta:
                    L.append((q, r))

    # Chọn ngẫu nhiên một nước đi từ danh sách tốt nhất
    if not L:
        return -1, -1
    return L[rd.randint(0, len(L) - 1)]

def tabu_search(max_iter):
    gen_initial_solution()

    for it in range(max_iter):
        violations = get_violations()
        print(f'Iter {it}: violations = {violations}')

        if violations == 0:
            return x  # Trả về kết quả nếu không còn vi phạm nào

        q, r = tabu_select(it)
        if q == -1:
            break  # Dừng lại nếu không có nước đi hợp lệ

        x[q] = r
        T[q][r] = it + tbl  # Cập nhật tabu cho nước đi này

    return x  # Trả về lời giải tốt nhất tìm được sau số lần lặp tối đa

if __name__ == '__main__':
    solution = tabu_search(1000)
    # print(solution)
    # print("Số vi phạm cuối:", get_violations())

    # Time complexity: O(n^4)