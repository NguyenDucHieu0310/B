// Bạn biết rằng một mảng có n số nguyên chỉ gồm các số từ 1 đến m và độ lệch giữa 2 phần tử liền kề trong mảng không được vượt quá 1 đơn vị.
// Bài toán đặt ra đó là cho bạn một mảng trong đó một số giá trị trong mảng chưa được xác định giá trị,
// nhiệm vụ của bạn là đếm số mảng phù hợp với mô tả,
// đó là các số liền kề trong mảng không lệch nhau quá 1 đơn vị và các giá trị trong mảng chỉ được nằm trong đoạn từ 1 tới m.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<vector<long long>> dp(n+1, vector<long long>(m+2, 0)); // thêm 2 để tránh out-of-bound

    // Khởi tạo
    for(int x=1; x<=m; x++) dp[0][x] = 1;

    for(int i=1; i<=n; i++) {
        if(a[i] != 0) {
            int x = a[i];
            dp[i][x] = dp[i-1][x];
            if(x-1 >= 1) dp[i][x] += dp[i-1][x-1];
            if(x+1 <= m) dp[i][x] += dp[i-1][x+1];
        } else {
            for(int x=1; x<=m; x++) {
                dp[i][x] = dp[i-1][x];
                if(x-1 >= 1) dp[i][x] += dp[i-1][x-1];
                if(x+1 <= m) dp[i][x] += dp[i-1][x+1];
            }
        }
    }

    long long ans = 0;
    for(int x=1; x<=m; x++) ans += dp[n][x];
    cout << ans << endl;

    return 0;
}