#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Giá trị vô cực
const int MAX_N = 100005; // Số giao lộ tối đa

// Hàm Dijkstra tính khoảng cách ngắn nhất từ một nguồn đến tất cả các đỉnh khác
vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INF); // Mảng khoảng cách
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src}); // {khoảng cách, đỉnh}
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue; // Bỏ qua nếu đã có đường ngắn hơn
        
        // Duyệt các đỉnh kề
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Hàm TSP tìm quãng đường ngắn nhất qua tất cả cửa hàng
int tsp(int pos, int mask, int s, vector<vector<int>>& dist, vector<vector<int>>& dp) {
    // Nếu đã thăm hết các cửa hàng, quay lại công ty (đỉnh 0)
    if (mask == (1 << s) - 1) {
        return dist[pos][0]; // Khoảng cách từ pos về công ty
    }
    
    // Nếu trạng thái đã được tính, trả về giá trị lưu trữ
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    
    int min_dist = INF; // Khởi tạo quãng đường nhỏ nhất
    
    // Thử đi đến các cửa hàng chưa thăm
    for (int next = 0; next < s; ++next) {
        if (!(mask & (1 << next))) { // Nếu cửa hàng next chưa thăm
            int dist_to_next = dist[pos][next + 1]; // +1 vì dist bao gồm công ty
            int new_dist = dist_to_next + tsp(next + 1, mask | (1 << next), s, dist, dp);
            min_dist = min(min_dist, new_dist);
        }
    }
    
    // Lưu kết quả vào bảng DP
    return dp[pos][mask] = min_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; // Số lượng test case
    cin >> T;
    
    while (T--) {
        int N, M; // Số giao lộ và số con đường
        cin >> N >> M;
        
        // Khởi tạo đồ thị dưới dạng danh sách kề
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; ++i) {
            int x, y, d;
            cin >> x >> y >> d;
            adj[x].push_back({y, d});
            adj[y].push_back({x, d}); // Đồ thị vô hướng
        }
        
        int S; // Số cửa hàng
        cin >> S;
        vector<int> stores(S); // Danh sách giao lộ chứa cửa hàng
        for (int i = 0; i < S; ++i) {
            cin >> stores[i];
        }
        
        // Tính khoảng cách ngắn nhất từ công ty và các cửa hàng đến nhau
        vector<vector<int>> dist(S + 1); // Ma trận khoảng cách (công ty + cửa hàng)
        dist[0] = dijkstra(0, N, adj); // Khoảng cách từ công ty (0)
        for (int i = 0; i < S; ++i) {
            dist[i + 1] = dijkstra(stores[i], N, adj); // Khoảng cách từ cửa hàng i
        }
        
        // Khởi tạo bảng DP cho TSP
        vector<vector<int>> dp(S + 1, vector<int>(1 << S, -1));
        
        // Gọi TSP từ công ty (0), với mask = 0 (chưa thăm cửa hàng nào)
        int result = tsp(0, 0, S, dist, dp);
        
        // In kết quả
        cout << result << endl;
    }
    
    return 0;
}