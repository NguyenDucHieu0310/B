/*
Bài toán: Triển khai cấu trúc dữ liệu Disjoint Set Union (DSU) với tối ưu path compression và union by size.

Các thành phần chính:
1. `find(u)`: tìm đại diện của tập chứa u. Kỹ thuật path compression giúp rút ngắn đường đi.
2. `Union(u, v)`: gộp hai tập chứa u và v. Sử dụng union by size để giữ cây cân bằng, giảm chiều cao.
3. `parent[i]`: lưu đại diện của tập chứa i.
4. `sz[i]`: kích thước của tập chứa i.

Input:
- Dòng 1: n m (số phần tử và số thao tác Union)
- m dòng tiếp theo: x y (thực hiện Union(x, y))

Output:
- Không có, đây chỉ là ví dụ triển khai DSU.

Ưu điểm:
- Tất cả các thao tác find/union gần như O(1) trung bình nhờ path compression và union by size.
*/


// CTDL Disjoint Set tối ưu

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1001;
int n, m;
int parent[MaxN];
int sz[MaxN];

int find(int u)
{
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

// cach 2 cua ham find
int find2(int u)
{
    if (u == parent[u]) {
        return u;
    }
    int tmp = find(parent[u]);
    parent[u] = tmp;
    return parent[u];
}

bool Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) {
        return false;
    } else if (sz[u] < sz[v]) {
        parent[u] = v;
        sz[v] += sz[u];
    } else {
        parent[v] = u;
        sz[u] += sz[v];
    }
    return true;
}

void khoiTao()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
}

int main()
{
    khoiTao();
    return 0;
}