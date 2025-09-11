/*
Đề bài:
Cho một dãy gồm n phần tử, đếm số cách chia dãy thành các phân đoạn liên tiếp (mỗi phân đoạn ít nhất 1 phần tử).

Input:
- Dòng 1: Số nguyên n (1 ≤ n ≤ 10^18)

Output:
- Một số nguyên: số cách chia dãy thành các phân đoạn liên tiếp modulo 10^9 + 7

Ví dụ:

Input:
3

Output:
4

Giải thích:
Với n = 3, các cách chia là:
1) [1][2][3]
2) [1][2,3]
3) [1,2][3]
4) [1,2,3]
*/



#include <bits/stdc++.h>
using namespace std;

// Xet tu k = 1 -> k = n;
// voi moi k thi can k - 1 thanh bar de chia thanh cac phan
// C(0, n - 1) + C(1, n - 1) + C(2, n - 1) + ... + C(n - 1, n - 1); (to hop);
// = 2^(n-1) % 1e9 + 7;
const int MOD = (int)1e9 + 7;
long long powMod(long long a, long long b)
{
    long long res = 1;
    while (b) {
        if (b % 2 == 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return res;
}

int main()
{
    long long n;
    cin >> n;
    cout << powMod(2, n - 1) << endl;
    return 0;
}