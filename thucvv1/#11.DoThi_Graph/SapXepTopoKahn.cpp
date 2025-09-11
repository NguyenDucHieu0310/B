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
- Dùng thuật toán Kahn (bfs):
    1. Tính indegree[i] = số cạnh đi vào đỉnh i.
    2. Tạo queue Q chứa các đỉnh indegree = 0.
    3. Lấy lần lượt đỉnh u từ queue:
        - Thêm u vào topo
        - Với các đỉnh v kề u, giảm indegree[v]--
        - Nếu indegree[v] == 0, push v vào queue
    4. Sau khi queue rỗng, topo là thứ tự topological.
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
    for (int x : topo) {
        cout << x << " ";
    }
    return 0;
}