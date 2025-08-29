#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file input.txt để đọc dữ liệu
    freopen("input.txt", "r", stdin);
    // Nếu muốn ghi kết quả ra file thì thêm dòng sau:
    // freopen("output.txt", "w", stdout);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];
    int sx = -1, sy = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] == 'O') { sx = i; sy = j; }
    vector<vector<char>> vis(n, vector<char>(m, 0));
    if (sx >= 0) vis[sx][sy] = 1;

    // order of preference when tie
    string order = "DRUL";
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string ans;
    int cx = sx, cy = sy;
    for (int step = 0; step < k; ++step) {
        int bestNew = -1;
        int bestDir = 0;
        int bestEx = cx, bestEy = cy;
        vector<pair<int,int>> bestPath;
        for (int t = 0; t < 4; ++t) {
            int dir;
            char ch = order[t];
            if (ch == 'D') dir = 0;
            else if (ch == 'R') dir = 1;
            else if (ch == 'U') dir = 2;
            else dir = 3;
            int x = cx, y = cy;
            vector<pair<int,int>> path;
            while (true) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                if (g[nx][ny] == '#') break;
                x = nx; y = ny;
                path.emplace_back(x,y);
            }
            int newCount = 0;
            for (auto &p : path) if (!vis[p.first][p.second]) ++newCount;
            if (newCount > bestNew) {
                bestNew = newCount;
                bestDir = dir;
                bestEx = x; bestEy = y;
                bestPath = path;
            }
        }
        char outc = 'D';
        if (bestDir == 0) outc = 'D';
        else if (bestDir == 1) outc = 'R';
        else if (bestDir == 2) outc = 'U';
        else outc = 'L';
        ans.push_back(outc);
        for (auto &p : bestPath) vis[p.first][p.second] = 1;
        cx = bestEx; cy = bestEy;
    }
    cout << ans << "\n";
    return 0;
}
