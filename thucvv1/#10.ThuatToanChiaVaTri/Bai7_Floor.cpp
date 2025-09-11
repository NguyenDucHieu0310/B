/*
Đề bài:
Cho một mảng đã sắp xếp tăng dần a[] gồm n phần tử và một số nguyên x. 
Tìm phần tử lớn nhất trong mảng mà không vượt quá x (nếu không có trả về -1).

Input:
- Dòng 1: Hai số nguyên n và x (1 ≤ n ≤ 10^5, |x| ≤ 10^9)
- Dòng 2: n số nguyên của mảng đã sắp xếp tăng dần a[0], a[1], ..., a[n-1]

Output:
- Một số nguyên: phần tử lớn nhất ≤ x trong mảng, nếu không có phần tử nào thỏa mãn thì in -1

Ví dụ:

Input:
5 7
1 3 5 6 10

Output:
6
*/


#include <bits/stdc++.h>
using namespace std;

int first_pos(int a[], int l, int r, int x, int ans)
{
    if (l > r) {
        return ans;
    }
    int m = (l + r) / 2;
    if (a[m] <= x) {
        ans = a[m];
        return first_pos(a, m + 1, r, x, ans);
    } else {
        return first_pos(a, l, m - 1, x, ans);
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << first_pos(a, 0, n - 1, x, -1) << endl;
    return 0;
}