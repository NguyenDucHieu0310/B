
/*
Cấu trúc dữ liệu Disjoint Set Union (DSU) hay Union-Find:

Mục đích:
- Quản lý các tập hợp rời nhau (disjoint sets) và hỗ trợ các thao tác:
  1. Tìm đại diện của tập hợp chứa một phần tử (find).
  2. Gộp hai tập hợp lại với nhau (union).

Các thành phần:
- `parent[i]`: đại diện của phần tử i. Nếu i là đại diện của tập, parent[i] = i.
- `sz[i]` (tùy chọn): kích thước của tập chứa i, dùng cho union by size.
- `find(u)`: trả về đại diện của tập chứa u.
- `Union(u, v)`: gộp hai tập chứa u và v, nếu khác nhau.

Ưu điểm:
- Dùng để đếm số thành phần liên thông trong đồ thị.
- Kiểm tra xem hai phần tử có thuộc cùng một tập hay không (có đường đi giữa 2 đỉnh).

Ví dụ sử dụng:
- Khởi tạo DSU với n đỉnh.
- Thực hiện m thao tác gộp Union(x, y).
- Đếm số thành phần liên thông: số lượng i sao cho i == parent[i].
- Kiểm tra kết nối: hai đỉnh u, v có cùng parent thì có đường đi.
*/



// cấu trúc dữ liệu disjoin set (DSU) (Union find) : Các tập hợp dời nhau

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1001;
int n, m; // so luong dinh va canh
int parent[MaxN]; // luu dinh dai dien
int sz[MaxN]; // size

// Tìm đại diện (parent)
int find(int u)
{
    while (u != parent[u]) {
        u = parent[u];
    }
    return parent[u]; // return u;
}

// Gộp
bool Union(int u, int v) // true: neu gop duoc (nếu 2 đỉnh không cùng 1 tập hợp)
{
    // tìm đại diện của u và đại diện của v
    u = find(u);
    v = find(v);
    if (u == v) { // nếu 2 đỉnh có cùng đại diện (cùng 1 tập hợp) thì không thể gộp
        return false;
    } else if (u < v) { // chọn đại diện nhỏ hơn làm đại diện
        parent[v] = u;
    } else {
        parent[u] = v;
    }
    return true;
}

void khoiTao()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i; // ban dau cho dai dien cua dinh hien tai bang chinh no
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y); // gop 2 dinh x, y
    }
}

int main()
{
    khoiTao();

    // in ra cac dinh va dai dien cua cac dinh
    for (int i = 1; i <= n; i++) {
        cout << i << " " << parent[i] << endl;
    }

    // dem so thanh phan lien thong: số lượng đỉnh thoả mãn (u = parent[u]);
    int tplt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == parent[i]) {
            ++tplt;
        }
    }
    cout << tplt << endl;

    // kiem tra 2 dinh co duong di hay k? : check 2 dinh neu co chung parent thi se co duong di

    return 0;
}