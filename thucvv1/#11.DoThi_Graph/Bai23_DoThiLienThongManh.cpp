// Đề bài:
// Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. 
// Hãy kiểm tra xem đồ thị có liên thông mạnh (strongly connected) hay không. 
// Nếu đồ thị liên thông mạnh, in ra 1, ngược lại in 0.

// Input:
// 4 5
// 1 2
// 2 3
// 3 4
// 4 1
// 2 4

// Output:
// 1



#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dske[1001];
bool visited[1001];

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : dske[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        DFS(i);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cout << "0" << endl;
                return 0;
            }
        }
    }
    cout << "1" << endl;
    return 0;
}