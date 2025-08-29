#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Giá trị vô cực để khởi tạo khoảng cách
int n; // Số lượng thành phố
vector<vector<int>> c; // Ma trận khoảng cách
map<pair<int, vector<bool>>, int> dp; // Bảng DP: dp[{pos, visited}] là quãng đường nhỏ nhất

// Hàm kiểm tra xem tất cả thành phố đã được thăm chưa
bool allVisited(const vector<bool>& visited) {
    for (int i = 1; i < n; ++i) { // Bỏ qua thành phố 1
        if (!visited[i]) return false;
    }
    return true;
}

// Hàm tính quãng đường nhỏ nhất từ thành phố pos với trạng thái visited
int tsp(int pos, vector<bool>& visited) {
    // Nếu đã thăm tất cả thành phố (trừ thành phố 1), quay về thành phố 1
    if (allVisited(visited)) {
        return c[pos][0]; // Khoảng cách từ pos về thành phố 1
    }
    
    // Tạo khóa cho bảng DP: cặp {pos, visited}
    pair<int, vector<bool>> state = {pos, visited};
    if (dp.find(state) != dp.end()) {
        return dp[state]; // Trả về giá trị đã tính
    }
    
    int min_dist = INF; // Khởi tạo khoảng cách nhỏ nhất
    
    // Thử đi đến các thành phố chưa thăm
    for (int next = 0; next < n; ++next) {
        if (!visited[next]) { // Nếu thành phố next chưa được thăm
            visited[next] = true; // Đánh dấu đã thăm
            // Tính quãng đường khi đi từ pos đến next, rồi tiếp tục từ next
            int dist = c[pos][next] + tsp(next, visited);
            min_dist = min(min_dist, dist); // Cập nhật quãng đường nhỏ nhất
            visited[next] = false; // Bỏ đánh dấu để thử trường hợp khác
        }
    }
    
    // Lưu kết quả vào bảng DP và trả về
    return dp[state] = min_dist;
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
    
    // Khởi tạo trạng thái visited: chỉ thành phố 1 (chỉ số 0) đã thăm
    vector<bool> visited(n, false);
    visited[0] = true;
    
    // Bắt đầu từ thành phố 1 (chỉ số 0)
    int result = tsp(0, visited);
    
    // In ra tổng khoảng cách nhỏ nhất
    cout << result << endl;
    
    return 0;
}