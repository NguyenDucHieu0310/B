/*
Đề bài:
Cho ma trận A[][] là ma trận vuông cỡ N x N. 
Hãy tính A^K (lũy thừa K của ma trận) và chia dư các phần tử trong ma trận kết quả cho 10^9 + 7.

Input:
- Dòng đầu tiên: hai số nguyên N K (1 ≤ N ≤ 10, 1 ≤ K ≤ 10^9)
- N dòng tiếp theo, mỗi dòng N số nguyên là các phần tử của ma trận A

Output:
- N dòng, mỗi dòng N số nguyên là phần tử của ma trận A^K (mod 10^9 + 7)

Ví dụ:

Input:
2 3
1 1
1 0

Output:
3 2
2 1

Input:
3 2
1 2 3
4 5 6
7 8 9

Output:
30 36 42
66 81 96
102 126 150
*/


// Cho ma trận A[][] là ma trận vuông cỡ N x N. Hãy tính kết quả A^K và chia dư các phần tử trong ma trận kết quả cho 10^9 + 7
#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;
int n, k;

struct matran {
    long long F[11][11];
    friend istream& operator>>(istream& in, matran& x)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x.F[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, matran x)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out << x.F[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
};

matran operator*(matran a, matran b)
{
    matran res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.F[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res.F[i][j] += a.F[i][k] * b.F[k][j];
                res.F[i][j] %= MOD;
            }
        }
    }
    return res;
}

matran powMod(matran a, long long k)
{
    if (k == 1) {
        return a;
    }
    matran x = powMod(a, k / 2);
    if (k % 2 == 1) {
        return x * x * a;
    } else {
        return x * x;
    }
}

int main()
{
    cin >> n >> k;
    matran a;
    cin >> a;
    matran res = powMod(a, k);
    cout << res << endl;
    return 0;
}