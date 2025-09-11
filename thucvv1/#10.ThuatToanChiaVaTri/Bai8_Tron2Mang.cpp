/*
Đề bài:
Cho hai mảng đã sắp xếp tăng dần a[] gồm n phần tử và b[] gồm m phần tử, tìm phần tử thứ k trong mảng hợp nhất của hai mảng.

Input:
- Dòng 1: Ba số nguyên n, m, k (1 ≤ n, m ≤ 10^5, 1 ≤ k ≤ n + m)
- Dòng 2: n số nguyên của mảng a[] đã sắp xếp tăng dần
- Dòng 3: m số nguyên của mảng b[] đã sắp xếp tăng dần

Output:
- Một số nguyên: phần tử thứ k trong mảng hợp nhất của a[] và b[]

Ví dụ:

Input:
5 4 5
1 3 5 7 9
2 4 6 8

Output:
5
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            cnt++;
            if (cnt == k) {
                cout << a[i] << endl;
                return 0;
            }
            ++i;
        } else {
            cnt++;
            if (cnt == k) {
                cout << b[j] << endl;
            }
            ++j;
        }
    }
    while (i < n) {
        cnt++;
        if (cnt == k) {
            cout << a[i] << endl;
            return 0;
        }
        i++;
    }
    while (j < m) {
        cnt++;
        if (cnt == k) {
            cout << b[j] << endl;
        }
        j++;
    }
    return 0;
}