/*
Đề bài:
Cho một đồ thị vô hướng dưới dạng danh sách kề (mỗi dòng i liệt kê các đỉnh kề của đỉnh i). Hãy chuyển sang danh sách cạnh (mỗi cạnh chỉ in một lần, đỉnh nhỏ hơn đứng trước).

Input:
- Dòng đầu tiên: số nguyên N là số đỉnh.
- N dòng tiếp theo: dòng thứ i liệt kê các đỉnh kề của đỉnh i, cách nhau bằng dấu cách.

Output:
- Liệt kê các cạnh theo thứ tự tăng dần: mỗi dòng hai số u v (u < v) biểu thị một cạnh.

Ví dụ:

Input:
5
2 3
1 3 4
1 2 5
2 5
3 4

Output:
1 2
1 3
2 3
2 4
3 5
4 5
*/


// Chuyển từ danh sách kề sang danh sách cạnh (do thi vo huong)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> a;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            if (i < stoi(tmp)) {
                a.push_back({ i, stoi(tmp) });
            }
        }
    }
    sort(a.begin(), a.end());
    for (auto it : a) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}