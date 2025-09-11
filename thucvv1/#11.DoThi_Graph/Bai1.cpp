/*
Đề bài:
Cho một đồ thị vô hướng với N đỉnh và M cạnh. Hãy xây dựng danh sách kề và in ra các đỉnh kề của từng đỉnh theo thứ tự tăng dần.

Input:
- Dòng đầu tiên: hai số nguyên N M (1 ≤ N ≤ 1000, 0 ≤ M ≤ N*(N-1)/2)
- M dòng tiếp theo, mỗi dòng hai số x y biểu thị một cạnh nối giữa đỉnh x và y

Output:
- N dòng, dòng thứ i in ra:
  i : danh sách các đỉnh kề của đỉnh i theo thứ tự tăng dần, cách nhau bởi dấu cách

Ví dụ:

Input:
5 6
1 2
1 3
2 3
2 4
3 5
4 5

Output:
1 : 2 3
2 : 1 3 4
3 : 1 2 5
4 : 2 5
5 : 3 4
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> dske[1001];
    int n, m;
    cin >> n >> m; // n dinh, m canh
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
        dske[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(dske[i].begin(), dske[i].end());
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int x : dske[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
