/*
Bài toán:
- Cho một cây với gốc là đỉnh 1, các đỉnh đánh số từ 1 tới n.
- Độ cao của một đỉnh là số cạnh trên đường đi ngắn nhất từ gốc tới đỉnh đó.
- Nhiệm vụ: xác định độ cao của tất cả các đỉnh.

Ý tưởng giải:
1. Lưu cây dưới dạng danh sách kề.
2. Dùng DFS bắt đầu từ gốc (đỉnh 1):
   - Với mỗi đỉnh con v của u chưa được thăm:
     - doCao[v] = doCao[u] + 1
     - DFS(v)
3. In ra độ cao của tất cả các đỉnh từ 1 tới n.

Ghi chú:
- DFS đảm bảo rằng mỗi đỉnh được tính đúng độ cao từ gốc.
- Mảng visited tránh lặp vô hạn.
*/


// Cho cây với đỉnh gốc là đỉnh 1, các đỉnh của cây được đánh số từ 1 tới n.
// Độ cao của một nốt trong cây được tính bằng số cạnh trên đường đi ngắn nhất giữa nốt này tới đỉnh gốc.
// Như vậy, gốc của cây là đỉnh 1 sẽ có độ cao là 0.
// Nhiệm vụ của bạn là hãy xác định chiều cao của mọi nốt trong cây. Dưới đây là một ví dụ về cây.

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dske[1001];
bool visited[1001];
int doCao[1001];

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
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
            doCao[v] = doCao[u] + 1;
            DFS(v);
        }
    }
}

int main()
{
    nhap();
    DFS(1);
    for (int i = 1; i <= n; i++) {
        cout << doCao[i] << " ";
    }
    cout << endl;
    return 0;
}