#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Giá trị vô cực để khởi tạo khoảng cách
int n; // Số lượng thành phố
vector<vector<int>> c; // Ma trận khoảng cách
vector<vector<int>> dp; // Bảng DP: dp[pos][mask] là quãng đường nhỏ nhất từ pos với trạng thái mask

// Hàm tính quãng đường nhỏ nhất từ thành phố pos với trạng thái mask
int tsp(int pos, int mask) {
    // Nếu đã thăm tất cả thành phố (trừ thành phố 1), quay về thành phố 1
    if (mask == (1 << n) - 1) {
        return c[pos][0]; // Khoảng cách từ pos về thành phố 1
    }
    
    // Nếu trạng thái đã được tính trước đó, trả về giá trị đã lưu
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    
    int min_dist = INF; // Khởi tạo khoảng cách nhỏ nhất là vô cực
    
    // Thử đi đến tất cả các thành phố chưa thăm
    for (int next = 0; next < n; ++next) {
        // Nếu thành phố next chưa được thăm (bit tương ứng là 0)
        if (!(mask & (1 << next))) {
            // Tính quãng đường khi đi từ pos đến next, rồi tiếp tục từ next
            int dist = c[pos][next] + tsp(next, mask | (1 << next));
            min_dist = min(min_dist, dist); // Cập nhật quãng đường nhỏ nhất
        }
    }
    
    // Lưu kết quả vào bảng DP và trả về
    return dp[pos][mask] = min_dist;
}

int main() {
    // Đọc số lượng thành phố
    cin >> n;
    
    // Khởi tạo ma trận khoảng cách
    c.assign(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }
    
    // Khởi tạo bảng DP với giá trị -1 (chưa tính)
    dp.assign(n, vector<int>(1 << n, -1));
    
    // Bắt đầu từ thành phố 1 (chỉ số 0), chưa thăm thành phố nào khác (mask = 1)
    int result = tsp(0, 1); // Bit 0 tương ứng với thành phố 1
    
    // In ra tổng khoảng cách nhỏ nhất
    cout << result << endl;
    
    return 0;
}