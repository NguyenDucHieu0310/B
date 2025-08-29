import heapq

def nthUglyNumber(n):
    if n <= 0:
        return 0

    ugly_numbers = [1]
    indices = [0, 0, 0]  # Con trỏ cho thừa số nguyên tố 2, 3, và 5

    for i in range(1, n):
        # Chọn số xấu tiếp theo
        next_ugly = min(ugly_numbers[indices[0]] * 2, ugly_numbers[indices[1]] * 3, ugly_numbers[indices[2]] * 5)

        # Tăng con trỏ cho thừa số nguyên tố đã được chọn
        if next_ugly == ugly_numbers[indices[0]] * 2:
            indices[0] += 1
        if next_ugly == ugly_numbers[indices[1]] * 3:
            indices[1] += 1
        if next_ugly == ugly_numbers[indices[2]] * 5:
            indices[2] += 1

        # Lặp cho đến khi có một số xấu mới lớn hơn số cuối cùng trong mảng
        

        ugly_numbers.append(next_ugly)

    return ugly_numbers[-1]

# Example usage
n = 15
print(f"The {n}-th ugly number is: {nthUglyNumber(n)}")
