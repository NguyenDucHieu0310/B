// ĐỀ BÀI

// Cho một mảng số nguyên đã được sắp xếp tăng dần gồm n phần tử và một số nguyên x.
// Hãy thực hiện các công việc sau:

// 1. Tìm chỉ số xuất hiện đầu tiên của x trong mảng.
// 2. Tìm chỉ số xuất hiện cuối cùng của x trong mảng.
// 3. Tìm chỉ số phần tử đầu tiên có giá trị ≥ x.
// 4. Tìm chỉ số phần tử đầu tiên có giá trị > x.
// 5. Tính số lần xuất hiện của x trong mảng.

// - Nếu x không tồn tại trong mảng, in -1 cho chỉ số xuất hiện đầu tiên và cuối cùng, đồng thời in 0 cho số lần xuất hiện.
// - Chỉ số của mảng được tính từ 0.

// INPUT
// - Dòng đầu tiên chứa hai số nguyên n và x — số phần tử của mảng và giá trị cần tìm.
// - Dòng tiếp theo chứa n số nguyên đã được sắp xếp tăng dần.

// OUTPUT
// In ra 5 dòng, lần lượt là:
// 1. Chỉ số xuất hiện đầu tiên của x.
// 2. Chỉ số xuất hiện cuối cùng của x.
// 3. Chỉ số phần tử đầu tiên có giá trị ≥ x.
// 4. Chỉ số phần tử đầu tiên có giá trị > x.
// 5. Số lần xuất hiện của x trong mảng.

// VÍ DỤ

// Ví dụ 1
// Input
// 10 5
// 1 2 5 5 5 6 7 9 10 11

// Output
// 2
// 4
// 2
// 5
// 3

// Ví dụ 2
// Input
// 6 8
// 1 3 5 7 9 11

// Output
// -1
// -1
// 4
// 4
// 0



#include <bits/stdc++.h>
using namespace std;

int bs1(int a[], int n, int x)
{
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) {
            res = m;
            r = m - 1;
        } else if (a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}
int bs2(int a[], int n, int x)
{
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) {
            res = m;
            l = m + 1;
        } else if (a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}
int bs3(int a[], int n, int x)
{
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] >= x) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return res;
}
int bs4(int a[], int n, int x)
{
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] > x) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return res;
}
int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x1 = bs1(a, n, x);
    int x2 = bs2(a, n, x);
    cout << x1 << endl;
    cout << bs2(a, n, x) << endl;
    cout << bs3(a, n, x) << endl;
    cout << bs4(a, n, x) << endl;
    if (x1 != -1) {
        cout << x2 - x1 + 1 << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
