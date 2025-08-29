#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

vector<int> dijkstra(int src, int n, const vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge: adj[u]) {
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

int tsp(int pos, int mask, int S, const vector<vector<int>>& dist, vector<vector<int>>& dp) {
    if (mask == (1 << S) - 1) return dist[pos][0];
    if (dp[pos][mask] != -1) return dp[pos][mask];
    int res = INF;
    for (int nxt = 1; nxt <= S; ++nxt) {
        if (!(mask & (1 << (nxt - 1)))) {
            res = min(res, dist[pos][nxt] + tsp(nxt, mask | (1 << (nxt - 1)), S, dist, dp));
        }
    }
    return dp[pos][mask] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; ++i) {
            int x, y, d;
            cin >> x >> y >> d;
            adj[x].push_back({y, d});
            adj[y].push_back({x, d});
        }
        int S;
        cin >> S;
        vector<int> stores(S);
        for (int i = 0; i < S; ++i) cin >> stores[i];

        vector<int> important = {0};
        important.insert(important.end(), stores.begin(), stores.end());
        int K = S + 1;

        vector<vector<int>> all_dist(K);
        for (int i = 0; i < K; ++i) {
            all_dist[i] = dijkstra(important[i], N, adj);
        }
        vector<vector<int>> dist(K, vector<int>(K, INF));
        for (int i = 0; i < K; ++i)
            for (int j = 0; j < K; ++j)
                dist[i][j] = all_dist[i][important[j]];

        vector<vector<int>> dp(K, vector<int>(1 << S, -1));
        int result = tsp(0, 0, S, dist, dp);
        cout << result << endl;
    }
    return 0;
}