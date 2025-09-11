/*
Đề bài:
Cho một mảng a[] gồm n phần tử chỉ chứa 0 và 1, được sắp xếp sao cho tất cả các số 0 nằm trước các số 1. Hãy tìm vị trí cuối cùng của số 0 (1-based). Nếu không có số 0, in ra 0.

Input:
- Dòng 1: Số nguyên n (1 ≤ n ≤ 10^5)
- Dòng 2: n số nguyên a[i] (0 hoặc 1), đã sắp xếp

Output:
- Một số nguyên: vị trí cuối cùng của số 0 trong mảng (1-based). Nếu không có 0, in 0.

Ví dụ:

Input:
6
0 0 0 1 1 1

Output:
3
*/


#include <bits/stdc++.h>
using namespace std;

int last_pos(int a[], int l, int r, int res)
{
    if (l > r) {
        return res;
    }
    int m = (l + r) / 2;
    if (a[m] == 0) {
        res = m;
        return last_pos(a, m + 1, r, res);
    } else {
        return last_pos(a, l, m - 1, res);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << last_pos(a, 0, n - 1, -1) + 1 << endl;
    return 0;
}