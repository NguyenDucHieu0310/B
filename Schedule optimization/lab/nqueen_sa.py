import random as rd

n = 30
x = [0] * n  # x[i] là hàng của quân hậu tại cột i

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

def metropolis(delta, temperature):
    return rd.random() < pow(2.71828, -delta / temperature)

def simulated_annealing(max_iter=10000):
    T = 1000
    alpha = 0.999
    min_T = 0.00000001

    gen_initial_solution()
    
    i = 0
    while T > min_T:
        i += 1

        # Chọn ngẫu nhiên một quân hậu và hàng mới
        q = rd.randint(0, n - 1)
        r = rd.randint(0, n - 1)
        
        # Tính delta và kiểm tra di chuyển theo Metropolis
        delta = get_delta(q, r)
        if delta < 0 or metropolis(delta, T):
            x[q] = r  # Chấp nhận di chuyển nếu có lợi hoặc theo hàm Metropolis

        # Giảm nhiệt độ
        T *= alpha

        violations = get_violations()
        if i % 100 == 0 or violations == 0 or T < min_T:
            print(f"Step {i}: Violations = {violations}")
        
        if violations == 0:
            return x  # Trả về lời giải nếu không còn xung đột

    # Trả về trạng thái cuối cùng nếu không có lời giải tối ưu
    return x

if __name__ == '__main__':
    # chọn số lần lặp lớn để tìm lời giải tốt nhất dựa trên n
    solution = simulated_annealing()
    # print("Lời giải cuối cùng:", solution)
    # print("Số vi phạm cuối:", get_violations())
