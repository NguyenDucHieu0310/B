#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const long long INF = 1e18;

vector<vector<pii>> adj;

vector<long long> dijkstra(int start, int N) {
    vector<long long> dist(N, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        adj.assign(N, {});

        for (int i = 0; i < M; ++i) {
            int x, y, d;
            cin >> x >> y >> d;
            adj[x].emplace_back(y, d);
            adj[y].emplace_back(x, d);
        }

        int S;
        cin >> S;
        vector<int> shops(S);
        for (int &s : shops) cin >> s;

        // Thêm điểm xuất phát (0) vào danh sách cần ghé
        shops.insert(shops.begin(), 0);
        S++;

        // Xây ma trận khoảng cách giữa các điểm cần ghé
        vector<vector<long long>> dist(S, vector<long long>(S));
        for (int i = 0; i < S; ++i) {
            vector<long long> d = dijkstra(shops[i], N);
            for (int j = 0; j < S; ++j) {
                dist[i][j] = d[shops[j]];
            }
        }

        // DP TSP: dp[mask][i] = chi phí nhỏ nhất để đi qua các điểm trong mask, kết thúc ở i
        int full = 1 << S;
        vector<vector<long long>> dp(full, vector<long long>(S, INF));
        dp[1][0] = 0; // Bắt đầu từ điểm 0

        for (int mask = 1; mask < full; ++mask) {
            for (int u = 0; u < S; ++u) {
                if (!(mask & (1 << u))) continue;
                for (int v = 0; v < S; ++v) {
                    if (mask & (1 << v)) continue;
                    int next_mask = mask | (1 << v);
                    dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }

        // Tìm chi phí nhỏ nhất quay lại điểm xuất phát (0)
        long long res = INF;
        for (int i = 1; i < S; ++i) {
            res = min(res, dp[full - 1][i] + dist[i][0]);
        }

        cout << res << '\n';
    }

    return 0;
}
// //vector<long long> dijkstra(int start, int N) {
//     vector<long long> dist(N, INF);
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     dist[start] = 0;
//     pq.push({0, start});

//     while (!pq.empty()) {
//         pii top = pq.top(); pq.pop();
//         int d = top.first, u = top.second;
//         if (d > dist[u]) continue;
//         for (auto edge : adj[u]) {
//             int v = edge.first, w = edge.second;
//             if (dist[v] > dist[u] + w) {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
//     return dist;
// }