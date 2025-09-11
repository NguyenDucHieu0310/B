/*
Đề bài:
Cho danh sách cạnh của một đồ thị vô hướng. Hãy chuyển sang ma trận kề.

Input:
- Dòng đầu: hai số nguyên n (số đỉnh), m (số cạnh)
- m dòng tiếp theo: mỗi dòng hai số x y biểu diễn một cạnh giữa đỉnh x và y

Output:
- Ma trận kề n x n, phần tử i,j = 1 nếu có cạnh i-j, 0 nếu không

Ví dụ:

Input:
4 4
1 2
2 3
1 4
3 4

Output:
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/


// Danh sách cạnh sang ma trận kề (vô hướng).
#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}