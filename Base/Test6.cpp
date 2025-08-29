#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Solve(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 3; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            for (int k = l + 1; k < r; ++k) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] + a[k] + a[r]);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << Solve(a) << endl;
    }
    return 0;
}