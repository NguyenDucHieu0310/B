
/*
ĐỀ BÀI:

Cho một đồ thị có hướng acyclic (DAG) gồm n đỉnh và m cạnh.  
Hãy tìm một sắp xếp topo (topological order) của các đỉnh.

Input:
- Dòng đầu tiên: 2 số nguyên n m (1 ≤ n ≤ 1000, 0 ≤ m ≤ 10000)
- m dòng tiếp theo: mỗi dòng 2 số nguyên x y (1 ≤ x, y ≤ n) biểu diễn cạnh từ x tới y.

Output:
- Một dòng n số nguyên là sắp xếp topo các đỉnh (các đỉnh cách nhau bởi dấu cách). Nếu có nhiều sắp xếp topo, in một sắp xếp bất kỳ.

Ý tưởng giải:
- Dùng DFS:
    1. Khởi tạo visited[i] = false.
    2. Với mỗi đỉnh i chưa thăm, gọi dfs(i)
    3. Trong dfs(u):
        - Đánh dấu visited[u] = true
        - Duyệt các đỉnh v kề với u, nếu chưa thăm gọi dfs(v)
        - Sau khi duyệt xong tất cả các đỉnh kề, push u vào topo
    4. Đảo ngược topo để được thứ tự topological
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dske[1001];
bool visited[1001];
vector<int> topo;

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : dske[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    topo.push_back(u); // tham xong thi cho vao sap xep topo
}

int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (int x : topo) {
        cout << x << " ";
    }
    return 0;
}