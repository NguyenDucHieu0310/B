Đề bài:
Cho ma trận trọng số của một đồ thị vô hướng n đỉnh (n x n). 
Hãy in ra danh sách cạnh với định dạng: "u v w" (u < v), trong đó w là trọng số của cạnh.

Input:
5
0 1 0 3 0
1 0 2 0 0
0 2 0 0 4
3 0 0 0 5
0 0 4 5 0

Output:
1 2 1
1 4 3
2 3 2
3 5 4
4 5 5


// Ma trận trọng số sang danh sách cạnh (vô hướng)

#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != 0 && i < j) {
                cout << i << " " << j << " " << a[i][j] << endl;
            }
        }
    }
    return 0;
}