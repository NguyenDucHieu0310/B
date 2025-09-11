/*
Đề bài:
Cho một đồ thị có hướng dưới dạng danh sách kề. Hãy chuyển sang danh sách cạnh (liệt kê tất cả các cạnh).

Input:
- Dòng đầu: số nguyên n (số đỉnh)
- n dòng tiếp theo: mỗi dòng liệt kê các đỉnh mà đỉnh i đi tới, cách nhau bằng dấu cách

Output:
- Liệt kê tất cả các cạnh dạng: "u v" (cạnh từ u đến v), sắp xếp theo u tăng dần, nếu u trùng thì theo v tăng dần

Ví dụ:

Input:
5
2 3
3 4
5
4 5
5

Output:
1 2
1 3
2 3
2 4
3 5
4 5
*/


// Chuyển từ danh sách kề sang danh sách cạnh (có hướng).
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            a.push_back({ i, stoi(tmp) });
        }
    }
    sort(a.begin(), a.end());
    for (auto it : a) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}