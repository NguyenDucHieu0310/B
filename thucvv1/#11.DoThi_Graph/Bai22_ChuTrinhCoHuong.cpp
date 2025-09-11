// Đề bài:
// Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. 
// Hãy kiểm tra xem đồ thị có chu trình hay không sử dụng DFS với đánh dấu màu (0: trắng, 1: xám, 2: đen). 
// Nếu có ít nhất một chu trình, in ra 1, ngược lại in 0.

// Input:
// 4 4
// 1 2
// 2 3
// 3 4
// 4 2

// Output:
// 1


#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dske[1001];
int color[1001];

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
                cout << "1" << endl;
                return 0;
            }
        }
    }
    cout << "0" << endl;
    return 0;
}