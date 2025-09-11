/*
Bài toán: Kiểm tra đồ thị vô hướng có chu trình hay không bằng BFS.

Ý tưởng:
- Dùng BFS duyệt từng thành phần liên thông:
  + Lưu parent của mỗi đỉnh khi duyệt.
  + Nếu gặp đỉnh đã visited mà không phải parent thì tồn tại chu trình.
- Nếu BFS tất cả các thành phần liên thông mà không phát hiện chu trình => đồ thị không có chu trình.

Input:
- Dòng 1: n m (số đỉnh, số cạnh)
- m dòng tiếp theo: x y (cạnh vô hướng giữa x và y)

Output:
- YES nếu đồ thị có chu trình
- NO nếu không có chu trình
*/



#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dske[1001];
int parent[1001];
bool visited[1001];

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
        dske[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

bool BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int v : dske[top]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = top;
                q.push(v);
            } else if (v != parent[top]) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (BFS(i)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}