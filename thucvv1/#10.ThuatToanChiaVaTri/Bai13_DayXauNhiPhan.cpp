/*
Đề bài:
Cho dãy Fibonacci nhị phân được định nghĩa như sau:
- F1 = "0"
- F2 = "1"
- Fn = Fn-2 + Fn-1 với n ≥ 3 (nối chuỗi)

Hãy tìm ký tự thứ K trong chuỗi Fibonacci nhị phân Fn.

Input:
- Một số nguyên n (1 ≤ n ≤ 93)
- Một số nguyên k (1 ≤ k ≤ độ dài Fn)

Output:
- Ký tự thứ K trong Fn (0 hoặc 1)

Ví dụ:

Input:
5
3

Output:
1

Input:
6
7

Output:
0
*/


#include <bits/stdc++.h>
using namespace std;

long long F[94];

void sinh()
{
    F[0] = 0;
    F[1] = 1; // F[2] = 1;
    for (int i = 2; i <= 93; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
}

int number(int n, long long k)
{
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (k <= F[n - 2]) {
        return number(n - 2, k);
    } else {
        return number(n - 1, k - F[n - 2]);
    }
}

int main()
{
    int n;
    cin >> n;
    sinh();
    long long k;
    cin >> k;
    cout << number(n, k) << endl;
    return 0;
}