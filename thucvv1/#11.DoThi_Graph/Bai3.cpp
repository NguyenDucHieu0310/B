/*
Đề bài:
Cho một đồ thị có hướng dưới dạng danh sách cạnh. Hãy chuyển sang danh sách kề (liệt kê các đỉnh mà mỗi đỉnh đi tới), sắp xếp thứ tự các đỉnh kề theo tăng dần.

Input:
- Dòng đầu: hai số nguyên n m (n: số đỉnh, m: số cạnh)
- m dòng tiếp theo: mỗi dòng hai số x y biểu diễn cạnh có hướng từ x đến y

Output:
- n dòng, mỗi dòng dạng:
  i : danh sách các đỉnh mà đỉnh i đi tới, cách nhau bằng dấu cách và sắp xếp tăng dần

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
2 : 3 4 
3 : 5 
4 : 5 
5 :
*/


// Chuyển danh sách cạnh sang danh sách kề (có hướng)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dske[1001];
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dske[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(dske[i].begin(), dske[i].end());
        cout << i << " : ";
        for (auto it : dske[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
}