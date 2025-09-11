/*
Đề bài:
Cho một mảng a[] gồm n số nguyên đã sắp xếp tăng dần. Kiểm tra xem một số k có xuất hiện trong mảng không.

Input:
- Dòng 1: Hai số nguyên n và k (1 ≤ n ≤ 10^5, |k| ≤ 10^9)
- Dòng 2: n số nguyên a[i] đã sắp xếp tăng dần

Output:
- "YES" nếu k xuất hiện trong mảng
- "NO" nếu k không xuất hiện trong mảng

Ví dụ:

Input:
5 3
1 2 3 4 5

Output:
YES

Input:
5 6
1 2 3 4 5

Output:
NO
*/


#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(int a[], int l, int r, int x)
{
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) {
            return true;
        } else if (a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (BinarySearch(a, 0, n - 1, k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}