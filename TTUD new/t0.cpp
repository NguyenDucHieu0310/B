#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int N = 6; // Number of vertices

vector<int> dist(N, INF);
vector<int> adj[N];
int w[N][N]; // Adjacency matrix
int C[7], D[7];
void BFS(int s) {
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

void buildGraph() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            w[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 1; i <= N; ++i) {
        BFS(i);
    }
}

void input() {
    int m;
    cin >> m; // Number of edges

    for (int i = 1; i <= N; ++i) {
        cin >> C[i] >> D[i]; // Read weights and distances
    }

    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v; // Read edges
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Dijkstra(int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == t) break;

        for (int v = 1; v <= N; ++v) {
            if (w[u][v] < INF) {
                if (dist[v] > dist[u] + w[u][v]) {
                    dist[v] = dist[u] + w[u][v];
                    pq.push({dist[v], v});
                }
            }
        }
    }

    cout << "Shortest distance from vertex " << s << " to vertex " << t << ": " << dist[t] << endl;
}

int main() {
    freopen("data.inp", "r", stdin);
    input();
    buildGraph();
    Dijkstra(1, N); // Find shortest path from vertex 1 to vertex N
    return 0;
}
