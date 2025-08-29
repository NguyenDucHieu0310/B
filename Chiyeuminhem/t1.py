def solve_test_case(a, b, c):
    a, b, c = str(a), str(b), str(c)

    len_a, len_b, len_c = len(a), len(b), len(c)

    digits = list(a) + list(b) + list(c)

    digits.sort(reverse=True)

    num_a = ['0'] * len_a
    num_b = ['0'] * len_b
    num_c = ['0'] * len_c

    lengths = [(len_a, num_a), (len_b, num_b), (len_c, num_c)]
    lengths.sort(reverse=True)  
    
    digit_idx = 0
    for length, num in lengths:
        for i in range(length):
            if digit_idx < len(digits):
                num[i] = digits[digit_idx]
                digit_idx += 1

    str_a = ''.join(num_a)
    str_b = ''.join(num_b)
    str_c = ''.join(num_c)

    if str_a == '0' * len_a and len_a > 1:
        str_a = '0'
    if str_b == '0' * len_b and len_b > 1:
        str_b = '0'
    if str_c == '0' * len_c and len_c > 1:
        str_c = '0'

    numbers = [str_a, str_b, str_c]
    max_result = ''
    from itertools import permutations
    for perm in permutations(numbers):
        result = ''.join(perm)
        if max_result == '' or result > max_result:
            max_result = result
    
    return max_result

K = int(input())
for _ in range(K):
    a, b, c = map(int, input().split())
    print(solve_test_case(a, b, c))