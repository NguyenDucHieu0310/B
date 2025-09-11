/*
Bài toán: Kiểm tra đồ thị vô hướng có chu trình hay không bằng DFS.

Ý tưởng:
- Với đồ thị liên thông:
  + Dùng DFS duyệt từ 1 đỉnh.
  + Nếu gặp đỉnh đã visited mà không phải parent => tồn tại chu trình.
- Với đồ thị không liên thông:
  + Duyệt tất cả các thành phần liên thông.
  + Nếu bất kỳ thành phần nào có chu trình => kết luận YES.
  + Nếu tất cả thành phần không có chu trình => kết luận NO.

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

bool DFS(int u, int par)
{
    visited[u] = true;
    for (int v : dske[u]) {
        if (!visited[v]) {
            if (DFS(v, u)) {
                return true;
            }
        } else if (v != par) {
            return true;
        }
    }
    return false;
}

// trong truong hop do thi la do thi lien thong
// int main()
// {
//     nhap();
//     if (DFS(1, 0)) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }
//     return 0;
// }

// truong hop do thi khong lien thong thi xet tat ca cac thanh phan lien thong
// neu thanh phan lien thong nao co chu trinh thi ket luan do thi do co chu trinh

int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (DFS(i, 0)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl; // sau lhi duyet tat ca cac thanh phan lien thong, ma khong thanh phan lien thong nao co chu trinh
    return 0;
}