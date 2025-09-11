import random
import time
import math

def init(n):
    """Khởi tạo ngẫu nhiên trạng thái ban đầu."""
    return [random.randint(0, n-1) for _ in range(n)]
    # return [i for i in range(n)]

def get_delta(queens, row, new_col):
    """Tính toán delta xung đột cho mỗi vị trí trong hàng row."""
    n = len(queens)

    def _get_conflict(col):
        """Tính tổng số xung đột tại vị trí cột col."""
        conflict = 0
        for i in range(n):
            if i != row:
                if queens[i] == col or \
                   queens[i] + i == col + row or \
                   queens[i] - i == col - row:
                    conflict += 1
        return conflict

    old_conflict = _get_conflict(queens[row])
    new_conflict = _get_conflict(new_col)

    return new_conflict - old_conflict

epsilon = 0.8
n_sample = 100

def step(queens):
    global epsilon, n_sample
    """Thực hiện một bước local search."""
    n = len(queens)
    row = random.randint(0, n-1)

    cols = random.sample(range(n), n_sample)
    deltas ={col: get_delta(queens, row, col) for col in cols}
    min_delta = min(deltas.values())
    min_indices = [col for col in cols if deltas[col] == min_delta]
    col = random.choice(min_indices)

    if min_delta < 0:
        queens[row] = col
        return min_delta
    elif random.random() < epsilon:
        queens[row] = col
        return min_delta

    return 0

    

def get_fitness(queens):
    """Tính tổng số xung đột trên bàn cờ."""
    n = len(queens)
    res = 0
    col = [0] * n
    diag1 = [0] * (2 * n - 1)
    diag2 = [0] * (2 * n - 1)

    for i in range(n):
        col[queens[i]] += 1
        diag1[i - queens[i] + n - 1] += 1
        diag2[i + queens[i]] += 1

    for x in col:
        res += x * (x - 1) // 2
    for x in diag1:
        res += x * (x - 1) // 2
    for x in diag2:
        res += x * (x - 1) // 2

    return res

def solve():
    global epsilon, n_sample
    n = int(input().strip())

    queens = init(n)
    conflict = get_fitness(queens)
    start_time = time.time()
    pre_time = start_time

    if n <= 100:
        n_sample = n
    elif n <= 500:
        n_sample = 50
    else:
        n_sample = 5

    for i in range(1000000):
        if time.time() - start_time > 10:
            break
        if time.time() - pre_time > 0.5:
            if epsilon > 0.2:
                epsilon *= 0.8
            pre_time = time.time()

        delta = step(queens)
        conflict += delta

        if conflict == 0:
            print(f"Step {i:<10} conflict: {conflict}")
            break

        if i%100 == 0:
            print(f"Step {i:<10} conflict: {conflict}")

    # print(n)
    # print(" ".join(str(x+1) for x in queens))

if __name__ == "__main__":
    solve()
