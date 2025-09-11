/*
Đề bài:
Tính (n^k) mod 10^9+7.

Input:
- Dòng 1: Hai số nguyên n, k (1 ≤ n, k ≤ 10^9)

Output:
- Một số nguyên: kết quả của (n^k) mod 10^9+7

Ví dụ:

Input:
2 10

Output:
1024
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

long long powMod(int a, int b)
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
    int a, b;
    cin >> a >> b;
    cout << powMod(a, b) << endl;
    return 0;
}