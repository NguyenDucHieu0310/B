/*
ĐỀ BÀI:

Cho một đồ thị vô hướng có n đỉnh và m cạnh, mỗi cạnh có trọng số w.  
Hãy tìm cây khung nhỏ nhất (Minimum Spanning Tree - MST) của đồ thị sử dụng thuật toán Prim.

Input:
- Dòng đầu tiên: 2 số nguyên n m (1 ≤ n ≤ 1000, 1 ≤ m ≤ 10000)
- m dòng tiếp theo, mỗi dòng 3 số nguyên x y w (1 ≤ x, y ≤ n, 1 ≤ w ≤ 1e9) biểu diễn cạnh giữa đỉnh x và y có trọng số w.

Output:
- Dòng đầu tiên: tổng trọng số của cây khung nhỏ nhất
- n-1 dòng tiếp theo: mỗi dòng 3 số u v w biểu diễn cạnh trong MST (không quan trọng thứ tự các cạnh)

Ý tưởng giải:
- Dùng thuật toán Prim:
    1. Khởi tạo tập V chứa các đỉnh chưa nằm trong MST, Vh chứa các đỉnh đã nằm trong MST.
    2. Khởi tạo d[i] = 1e9 (trọng số nhỏ nhất từ Vh tới i), parent[i] = -1.
    3. Bắt đầu từ đỉnh s, push (0, s) vào priority_queue.
    4. Lặp: lấy đỉnh u có trọng số nhỏ nhất, nếu u chưa dùng:
        - đánh dấu u đã dùng
        - cộng trọng số vào MST
        - lưu parent[u] để xuất cạnh
        - duyệt các đỉnh kề v chưa dùng: nếu w(u,v) < d[v], cập nhật d[v] = w(u,v), parent[v] = u, push (d[v], v) vào heap
    5. Khi heap rỗng, MST hoàn tất.
*/


#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> dske[1001];
bool used[1001];

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dske[x].push_back({ y, w });
        dske[y].push_back({ x, w });
    }
    memset(used, false, sizeof(used));
}

void Prim(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({ 0, s }); // 0 la dinh, s la trong so
    int res = 0; // luu trong so min cua cay
    while (!Q.empty()) {
        pair<int, int> top = Q.top();
        Q.pop();
        int w = top.first;
        int x = top.second;
        if (used[x] == true) {
            continue;
        }
        res += w;
        used[x] = true;
        for (auto it : dske[x]) {
            int y = it.first; // dinh ke voi dinh x;
            int w1 = it.second; // trong so cua canh x, y;
            Q.push({ w1, y });
        }
    }
    cout << res << endl;
}

int main()
{
    nhap();
    Prim(1);
    return 0;
}