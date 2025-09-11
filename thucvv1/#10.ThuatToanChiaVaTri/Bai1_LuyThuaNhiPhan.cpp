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

long long powMod(int n, int k)
{
    if (k == 0) {
        return 1;
    }
    long long x = powMod(n, k / 2);
    if (k % 2 == 0) {
        return ((x % MOD) * (x % MOD) % MOD);
    } else {
        return (((x % MOD) * (x % MOD)) % MOD * (n % MOD)) % MOD;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << powMod(n, k) << endl;
    return 0;
}