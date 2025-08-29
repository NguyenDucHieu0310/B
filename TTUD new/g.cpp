#include <bits/stdc++.h> 
using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int Step(vector<vector<int>>& a, vector<vector<int>>& step, vector<vector<bool>>& visited, int r, int c) {
    int n = a.size();
    int m = a[0].size();

    if (a[r][c] == 1) return INT_MAX - 1;
    if (step[r][c] != 0) return step[r][c];
    if (r == 0 || r == n - 1 || c == 0 || c == m - 1) return 1;

    int minWay = INT_MAX - 1;
    for (int i = 0; i < 4; i++) {
        int newrow = r + dr[i];
        int newcol = c + dc[i];

        if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !visited[newrow][newcol]) {
            visited[newrow][newcol] = true;
            minWay = min(Step(a, step, visited, newrow, newcol), minWay);
            visited[newrow][newcol] = false;
        }
    }

    step[r][c] = minWay + 1;
    return step[r][c];
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> step(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
        }

    visited[r - 1][c - 1] = true;
    cout << Step(a, step, visited, r - 1, c - 1);

    return 0;
}
