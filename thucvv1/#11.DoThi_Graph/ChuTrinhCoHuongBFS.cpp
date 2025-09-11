/*
Bài toán: Kiểm tra đồ thị có chu trình hay không bằng thuật toán sắp xếp topo Kahn.

Ý tưởng:
- Đồ thị có hướng được biểu diễn bằng danh sách kề.
- indegree[i] = số cạnh đi vào đỉnh i.
- Sử dụng thuật toán Kahn:
   1. Đưa tất cả các đỉnh có indegree = 0 vào queue.
   2. Lấy đỉnh ra khỏi queue, giảm indegree của các đỉnh kề.
   3. Nếu một đỉnh có indegree = 0 thì thêm vào queue.
- Nếu số lượng đỉnh đã duyệt != n thì tồn tại chu trình.

Input:
- Dòng 1: n m (số đỉnh, số cạnh)
- m dòng tiếp theo: x y (cạnh hướng từ x -> y)

Output:
- 1 nếu tồn tại chu trình, 0 nếu không có chu trình.
*/


#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dske[1001];
int indegree[1001];
vector<int> topo;

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
        indegree[y]++;
    }
}

void kahn()
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        topo.push_back(top);
        for (int v : dske[top]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main()
{
    nhap();
    kahn();
    if (topo.size() != n) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}