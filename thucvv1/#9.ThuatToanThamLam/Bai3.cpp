/*
Đề bài:
Cho một mảng a gồm n số nguyên.
Hãy sắp xếp mảng theo thứ tự tăng dần và tính tổng:

    sum = Σ (a[i] * i) mod 1e9+7

Input:
- Dòng 1: số nguyên n (1 ≤ n ≤ 10^5)
- Dòng 2: n số nguyên a[i] (1 ≤ a[i] ≤ 10^9)

Output:
- Một số nguyên: tổng modulo 10^9+7

Ví dụ:

Input:
5
5 2 4 3 1

Output:
40
*/


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 1ll * a[i] * i;
        sum %= MOD;
    }
    cout << sum << endl;
    return 0;
}