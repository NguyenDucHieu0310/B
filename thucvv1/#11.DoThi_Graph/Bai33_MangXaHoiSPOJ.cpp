/*
Đề bài:
Tý xây dựng một mạng xã hội. Mạng hoàn hảo được định nghĩa:
Với mọi bộ ba X, Y, Z: nếu X kết bạn với Y và Y kết bạn với Z thì X cũng phải kết bạn với Z.

Input:
- n: số người dùng
- m: số cặp kết bạn
- m dòng: mỗi dòng hai số x y, nghĩa là x và y là bạn

Yêu cầu:
Xác định mạng xã hội hiện tại có là hoàn hảo hay không. Nếu có in "YES", ngược lại in "NO".

Ý tưởng giải:
1. Dùng DFS để tìm các thành phần liên thông.
2. Trong một thành phần liên thông, nếu mọi người đều kết bạn với tất cả các thành viên khác, thì thành phần đó là hoàn hảo.
3. Kiểm tra với mỗi thành phần: nếu độ của mỗi node = số node trong thành phần - 1, thì thỏa.

Ví dụ:
Input:
4 4
1 2
2 3
3 1
4 4
Output:
YES

Giải thích:
- Có hai thành phần: {1,2,3} và {4}
- Thành phần {1,2,3} là một tam giác hoàn hảo (mỗi người kết bạn với 2 người còn lại)
- Thành phần {4} có 0 bạn bè, cũng thỏa
- Mạng xã hội hoàn hảo -> in YES
*/


// Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử.
// Bạn của bạn cũng là bạn. Vì vậy, Tý muốn mạng xã hội của mình là hoàn hảo, tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội.
// Các bạn hãy xác định xem mạng xã hội hiện tại của Tý có là hoàn hảo hay không?
// Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dske[1001];
bool visited[1001];
int dem = 1;
vector<int> tplt[1001];

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

void dfs(int u)
{
    visited[u] = true;
    tplt[dem].push_back(u);
    for (int v : dske[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            dem++;
        }
    }
    for (int i = 1; i <= dem; i++) {
        for (int j : tplt[i]) {
            if (tplt[i].size() - 1 != dske[j].size()) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}