// Đề bài:
// Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. 
// Cho trước hai đỉnh s và t. Hãy tìm đường đi từ s đến t bằng thuật toán DFS. 
// Nếu không có đường đi, in ra -1.

// Input:
// 6 7 1 6
// 1 2
// 1 3
// 2 4
// 2 5
// 3 5
// 4 6
// 5 6

// Output:
// 1 2 4 6


#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> dske[1001];
bool visited[1001];
int pre[1001];

void nhap()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
        dske[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(dske[i].begin(), dske[i].end());
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : dske[u]) {
        if (!visited[v]) {
            pre[v] = u;
            DFS(v);
        }
    }
}

int main()
{
    nhap();
    DFS(s);
    if (!visited[t]) {
        cout << "-1" << endl;
    } else {
        vector<int> path;
        while (s != t) {
            path.push_back(t);
            t = pre[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}