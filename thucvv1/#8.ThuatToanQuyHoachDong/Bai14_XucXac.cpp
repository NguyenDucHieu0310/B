// ## Đề bài
// Cho một con xúc xắc 6 mặt. Hãy tính số cách để tung xúc xắc nhiều lần sao cho tổng các mặt ngửa bằng `n`. Kết quả in ra modulo 10^9 + 7.

// ## Input
// - Một số nguyên `n` (1 ≤ n ≤ 10^5)

// ## Output
// - Một số nguyên duy nhất: số cách tung xúc xắc để tổng bằng `n`, modulo 10^9 + 7.

// ## Ví dụ

// ### Input
// 3

// ### Output
// 4

// (Giải thích: Các cách là [1+1+1], [1+2], [2+1], [3])


#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

int main()
{
    ios::sync_with_stdio(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i >= j) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}