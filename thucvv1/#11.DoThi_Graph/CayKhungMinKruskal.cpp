/*
Bài toán:
- Tìm cây khung nhỏ nhất (Minimum Spanning Tree - MST) của đồ thị vô hướng có trọng số.
- Sử dụng thuật toán Kruskal (tham lam).

Input:
- Dòng 1: n m (số đỉnh, số cạnh)
- m dòng tiếp theo: x y w (cạnh giữa x và y có trọng số w)

Output:
- Trọng số tổng của cây khung nhỏ nhất
- Danh sách các cạnh trong cây khung nhỏ nhất (x y w)

Ý tưởng giải:
1. Lưu đồ thị dưới dạng danh sách cạnh (mảng các struct canh {x, y, w}).
2. Dùng thuật toán Kruskal:
   - Sắp xếp các cạnh theo trọng số tăng dần.
   - Dùng Disjoint Set Union (DSU) để kiểm tra chu trình:
     - Nếu hai đỉnh của cạnh thuộc cùng tập hợp => bỏ qua (tạo chu trình)
     - Ngược lại => thêm cạnh vào MST và gộp hai tập hợp.
   - Dừng khi MST có đủ n-1 cạnh.
3. Kết quả:
   - Tổng trọng số MST
   - Các cạnh thuộc MST
*/


// tìm cây khung nhỏ nhất sử dụng thuật toán Kruskal (tham lam)

#include <bits/stdc++.h>
using namespace std;

struct canh {
    int x, y, w;
    // (x, y) : la 1 canh
    // w : la trong so
};

const int MaxN = 1001;
int n, m;
int parent[MaxN];
int sz[MaxN];
vector<canh> edge;

int find(int u)
{
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = find(parent[u]);
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
    // khoi tao cho disjoint set (DSU)
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        canh tmp = { x, y, w };
        edge.push_back(tmp);
    }
}

bool cmp(canh a, canh b)
{
    return a.w < b.w;
}

void Kruskal()
{
    // khoi tao do dai cay khung
    int d = 0; // trong so cay khung

    // sap xep canh theo trong so tang dan
    sort(edge.begin(), edge.end(), cmp);

    vector<canh> MST; // minimum spanning tree: cay khung cuc tieu

    for (int i = 0; i < m; i++) { // duyet cac canh
        if (MST.size() == n - 1) { // neu da du so canh thi dung lai (n - 1 canh)
            break;
        }

        int x = edge[i].x;
        int y = edge[i].y;
        int w = edge[i].w;

        if (Union(x, y)) { // neu co the gop 2 dinh x,y (khong tao nen chu trinh)
            MST.push_back(edge[i]);
            d += w;
        }
    }
    cout << "trong so cua cay khung cuc tieu: " << d << endl;
    for (auto it : MST) {
        cout << it.x << " " << it.y << " " << it.w << endl;
    }
}

int main()
{
    khoiTao();
    Kruskal();
    return 0;
}