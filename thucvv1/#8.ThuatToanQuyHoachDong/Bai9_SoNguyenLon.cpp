/*
ĐỀ BÀI: TÌM ĐỘ DÀI DÃY CON CHUNG DÀI NHẤT (LCS)

Cho hai chuỗi ký tự s và t.
Hãy tìm độ dài của dãy con chung dài nhất (Longest Common Subsequence — LCS) giữa hai chuỗi.

Input:
- Dòng 1: Chuỗi s (độ dài ≤ 1000).
- Dòng 2: Chuỗi t (độ dài ≤ 1000).

Output:
- Một số nguyên duy nhất — độ dài dãy con chung dài nhất giữa s và t.

Ví dụ:

Input
abcbdab
bdcaba

Output
4

(Vì LCS có thể là bcba hoặc bdab hoặc bcab đều có độ dài 4).
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    s = "a" + s;
    int n = s.length();
    t = "a" + t;
    int m = t.length();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}