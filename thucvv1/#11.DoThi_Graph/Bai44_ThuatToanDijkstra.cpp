/*
Bài toán:
- Cho đồ thị vô hướng có trọng số với n đỉnh, m cạnh.
- Tính khoảng cách ngắn nhất từ đỉnh s tới tất cả các đỉnh còn lại.

Input:
- Dòng 1: n m s (số đỉnh, số cạnh, đỉnh xuất phát)
- m dòng tiếp theo: x y w (cạnh giữa x và y có trọng số w)

Output:
- 1 dòng n số: d[1] d[2] ... d[n], trong đó d[i] là khoảng cách ngắn nhất từ s tới i.

Ý tưởng giải:
1. Lưu đồ thị dưới dạng danh sách kề, mỗi cạnh lưu kèm trọng số.
2. Dùng thuật toán Dijkstra:
   - Khởi tạo d[i] = vô cực, d[s] = 0.
   - Dùng priority_queue min-heap để lấy đỉnh có khoảng cách nhỏ nhất chưa xử lý.
   - Với mỗi đỉnh v được lấy ra:
     - Nếu khoảng cách hiện tại > d[v], bỏ qua.
     - Duyệt tất cả các đỉnh kề y:
       - Nếu d[y] > d[v] + w(v,y) thì cập nhật d[y] = d[v] + w(v,y) và đẩy vào heap.
3. Sau khi hoàn tất, d[i] là khoảng cách ngắn nhất từ s tới i.

Ghi chú:
- priority_queue với `greater<pair<int,int>>` đảm bảo lấy đỉnh có khoảng cách nhỏ nhất.
- Đồ thị vô hướng nên thêm cả cạnh {y,x} cho mỗi cạnh {x,y}.
*/


#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<pair<int, int>> dske[1001];
int d[1001]; // luu khoang cach

void nhap()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dske[x].push_back({ y, w });
        dske[y].push_back({ x, w }); // do thi vo huong
    }
}

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    d[s] = 0;
    // d[i]: khoang cach ngan nhat tu dinh s toi dinh i

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({ 0, s });

    while (!Q.empty()) {
        pair<int, int> top = Q.top();
        Q.pop();
        int distance = top.first; // khoang cach tu dinh s toi dinh hien tai
        int v = top.second;

        // check
        if (distance > d[v]) {
            continue;
        }
        // relaxation
        // duyet cac dinh ke voi dinh v va cap nhat
        for (auto it : dske[v]) {
            int y = it.first, w = it.second;
            if (d[y] > d[v] + w) {
                d[y] = d[v] + w;
                Q.push({ d[y], y });
            }
        }
    }
}

int main()
{
    nhap();
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}