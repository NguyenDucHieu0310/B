#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n;
vector<int> adj[MAXN];
int subtree[MAXN];
int centroid = -1;

void dfs(int u, int p) {
    subtree[u] = 1;
    int maxSub = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        subtree[u] += subtree[v];
        maxSub = max(maxSub, subtree[v]);
    }
    maxSub = max(maxSub, n - subtree[u]);

    if (maxSub <= n / 2) centroid = u;
}

void printAdjList() {
    cout << "Danh sach ke hien tai:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int v : adj[i]) cout << v << " ";
        cout << "\n";
    }
    cout << "------------------\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        cout << "Them canh " << a << " - " << b << "\n";
        printAdjList();
    }

    dfs(1, -1);
    cout << "Centroid = " << centroid << "\n";
    return 0;
}
