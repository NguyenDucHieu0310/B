// ## Đề bài
// Cho một số nguyên dương `n`. Hãy đếm số cách **chia tập hợp `{1, 2, ..., n}` thành hai tập con có tổng bằng nhau**.  

// Do kết quả có thể rất lớn, in kết quả modulo 10^9 + 7.

// ## Input
// - Dòng 1: Số nguyên `n` (1 ≤ n ≤ 500)

// ## Output
// - Một số nguyên: số cách chia tập `{1..n}` thành hai tập con có tổng bằng nhau modulo 10^9 + 7

// ## Ví dụ

// ### Input
// 7

// ### Output
// 4

// (Giải thích: Có 4 cách chia `{1,2,3,4,5,6,7}` thành hai tập con có tổng bằng nhau)


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << "0\n";
        return 0;
    }
    sum /= 2;
    vector<vector<int>> res(n + 1, vector<int>(sum + 1, 0));
    res[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            res[i][j] = res[i - 1][j];
            if (j >= i) {
                res[i][j] += res[i - 1][j - i];
                res[i][j] %= mod;
            }
        }
    }
    cout << res[n - 1][sum] << endl;
    return 0;
}