/*
Bài toán: Kiểm tra đồ thị có hướng có chu trình hay không bằng DFS và đánh dấu màu.

Ý tưởng:
- Dùng 3 màu cho các đỉnh:
  + 0 (trắng): chưa tham
  + 1 (xám): đang tham (DFS đang duyệt)
  + 2 (đen): đã tham xong
- DFS từ mỗi đỉnh trắng:
   - Nếu gặp đỉnh xám => tồn tại chu trình.
   - Sau khi DFS xong đỉnh, đổi màu thành đen.
- Nếu DFS tất cả các đỉnh mà không gặp đỉnh xám nào, đồ thị không có chu trình.

Input:
- Dòng 1: n m (số đỉnh, số cạnh)
- m dòng tiếp theo: x y (cạnh hướng từ x -> y)

Output:
- YES nếu đồ thị có chu trình
- NO nếu không có chu trình
*/


#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dske[1001];
int color[1001]; // su dung 3 mau: trang, xam, den
// trang: chua tham;
// xam: dang tham (da tham nhung chua xong);
// den: da tham xong; 

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
    }
    memset(color, 0, sizeof(color));
}

bool DFS(int u)
{
    color[u] = 1; // chuyen thanh mau xam
    for (int v : dske[u]) {
        if (color[v] == 0) {
            if (DFS(v)) {
                return true;
            }
        } else if (color[v] == 1) {
            return true;
        }
    }
    color[u] = 2; // chuyen thanh mau den
    return false;
}

int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (DFS(i)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}