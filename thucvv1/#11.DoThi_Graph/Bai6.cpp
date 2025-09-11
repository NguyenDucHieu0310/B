/*
Đề bài:
Cho ma trận kề của một đồ thị vô hướng. Hãy chuyển sang:
1. Danh sách cạnh (liệt kê tất cả các cạnh, mỗi cạnh in một lần)
2. Danh sách kề của từng đỉnh

Input:
- Dòng đầu: số nguyên n (số đỉnh)
- n dòng tiếp theo: ma trận kề n x n (0 hoặc 1)

Output:
- Danh sách cạnh (mỗi dòng "u v" với u>v để không lặp)
- Một dòng trống
- Danh sách kề từng đỉnh: "i : x1 x2 x3 ..." (các đỉnh kề với i)

Ví dụ:

Input:
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

Output:
2 1
3 2
4 1
4 3

1 : 2 4
2 : 1 3
3 : 2 4
4 : 1 3
*/


#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                cout << i << " " << j << endl;
            }
        }
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}