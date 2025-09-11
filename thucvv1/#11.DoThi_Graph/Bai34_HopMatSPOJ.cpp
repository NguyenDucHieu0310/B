/*
Bài toán:
- Có K người đứng ở N địa điểm, các địa điểm nối với nhau bằng M đường đi một chiều.
- Mọi người muốn tụ họp tại một địa điểm chung.
- Cần xác định có bao nhiêu điểm có thể được chọn làm điểm họp mặt sao cho tất cả mọi người đều đi tới đó được.

Ý tưởng giải:
1. Lưu trữ đồ thị theo dạng danh sách kề.
2. Với mỗi người, DFS từ vị trí ban đầu của người đó:
   - đánh dấu các đỉnh mà người đó có thể đi tới
   - tăng biến đếm `dem[u]` cho đỉnh u mỗi lần người có thể tới được.
3. Sau khi duyệt tất cả K người:
   - Nếu `dem[i] == K` nghĩa là tất cả K người đều có thể đi tới i -> điểm đó hợp lệ.
4. Đếm các điểm hợp lệ và in ra.

Lưu ý:
- Vì N ≤ 1000, M ≤ 10000, DFS từ mỗi người là khả thi.
- Cần reset mảng `visited` trước khi DFS cho mỗi người.
*/



// Có K người (1 ≤ K ≤ 100) đứng tại vị trí nào đó trong N địa điểm cho trước (1 ≤ N ≤ 1,000) được đánh số từ 1..N.
// Các điểm được nối với nhau bởi M đoạn đường một chiều (1 ≤ M ≤ 10,000) (không có đoạn đường nào nối một điểm với chính nó).
// Mọi người muốn cùng tụ họp tại một địa điểm nào đó.
// Tuy nhiên, với các đường đi cho trước, chỉ có một số địa điểm nào đó có thể được chọn là điểm họp mặt.
// Cho trước K, N, M và vị trí ban đầu của K người cùng với M đường đi một chiều, hãy xác định xem có bao nhiêu điểm có thể được chọn làm điểm họp mặt.

#include <bits/stdc++.h>
using namespace std;

int k, n, m;
vector<int> dske[1001];
vector<int> vitri;
bool visited[1001];
int dem[1001]; // dem xem cac dinh hien tai co bao nhieu dinh di qua duoc no? neu dem[i] == thi dinh do thoa man

void nhap()
{
    cin >> k >> n >> m;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        vitri.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    dem[u]++; // dem cac dinh co the di qua
    visited[u] = true;
    for (int v : dske[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main()
{
    int cnt = 0;
    nhap();
    for (int x : vitri) {
        memset(visited, false, sizeof(visited));
        dfs(x);
    }
    for (int i = 1; i <= n; i++) {
        if (dem[i] == k) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}