/*
Bài toán:
- Tìm cây khung nhỏ nhất (Minimum Spanning Tree - MST) của đồ thị vô hướng có trọng số.
- Sử dụng thuật toán Prim (tham lam).

Input:
- Dòng 1: n m (số đỉnh, số cạnh)
- m dòng tiếp theo: x y w (cạnh giữa x và y có trọng số w)

Output:
- Tổng trọng số của cây khung nhỏ nhất
- Danh sách các cạnh trong cây khung nhỏ nhất (x y w)

Ý tưởng giải:
1. Dùng tập Vh chứa các đỉnh đã nằm trong cây khung, tập V chứa các đỉnh chưa có trong cây khung.
2. Khởi tạo:
   - Chọn 1 đỉnh bất kỳ làm đỉnh bắt đầu s.
   - Gán trọng số d[i] = INF cho tất cả các đỉnh, d[s] = 0.
3. Dùng priority_queue để lấy đỉnh x thuộc V có cạnh (x, y) trọng số nhỏ nhất nối với Vh:
   - Nếu đỉnh x chưa dùng (chưa vào Vh) thì thêm x vào MST, cập nhật tổng trọng số.
   - Duyệt các đỉnh kề y của x:
       - Nếu y chưa vào Vh và w(x, y) < d[y] thì cập nhật d[y] = w(x, y) và parent[y] = x.
4. Lặp lại cho đến khi tất cả đỉnh đã nằm trong MST.
5. Kết quả:
   - Tổng trọng số MST
   - Các cạnh thuộc MST
*/



#include <bits/stdc++.h>
using namespace std;

// duy trì tập V: chứa các đỉnh chưa nằm trong cây khung, tập Vh chứa các đỉnh đã nằm trong cây khung
// ở mỗi bước lấy ra cạnh có trọng số nhỏ nhất thoả mãn 1 đỉnh thuộc V, 1 đỉnh thuộc Vh

struct canh {
    int x, y, w; // canh gom dinh (x, y) va trong so w
};

const int MaxN = 1001;
int n, m; // so luong dinh va canh
vector<pair<int, int>> dske[MaxN];
bool used[MaxN]; // neu true thi thuoc Vh (tap cua cay khung), neu false thuoc V
int d[MaxN]; // luu trong so nho nhat
int parent[MaxN];

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dske[x].push_back({ y, w }); // first la dinh, second la trong so
        dske[y].push_back({ x, w });
    }
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
}

void Prim(int s) // bat dau tu dinh s
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    int res = 0; // do dai (trong so) cua cay khung
    Q.push({ 0, s }); // first la trong so, second la dinh
    vector<canh> MST; // danh sach canh cua cay khung
    while ((!Q.empty())) {
        pair<int, int> top = Q.top();
        Q.pop();
        int w = top.first;
        int x = top.second;
        if (used[x] == true) {
            continue;
        }
        res += w;
        used[x] = true;
        if (x != s) {
            MST.push_back({ x, parent[x], w });
        }
        // duyet tat ca dinh ke voi x
        for (auto it : dske[x]) {
            int y = it.first; // y la dinh ke cua x
            int w1 = it.second; // w1 la trong so canh (x, y);
            if (!used[y] && d[y] > w1) {
                Q.push({ w1, y });
                parent[y] = x;
                d[y] = w1;
            }
        }
    }
    cout << res << endl;
    for (auto it : MST) {
        cout << it.x << " " << it.y << " " << it.w << endl;
    }
}

int main()
{
    nhap();
    Prim(1); // duyet tu dinh 1
    return 0;
}