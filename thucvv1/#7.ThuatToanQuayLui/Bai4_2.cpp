// ĐỀ BÀI

// Cho một mảng gồm n số nguyên dương và một số nguyên k.  
// Hãy liệt kê tất cả các tập con **các phần tử phân biệt** của mảng sao cho tổng của tập con bằng k.  

// Nếu không có tập con nào thỏa mãn, in ra `-1`.

// INPUT
// - Dòng 1: hai số nguyên n, k — số phần tử của mảng và giá trị cần đạt.
// - Dòng 2: n số nguyên dương — các phần tử của mảng.

// OUTPUT
// - Mỗi dòng là một tập con có tổng bằng k, in theo định dạng `[x1 x2 ... xt]` với:
//   - Các phần tử trong tập con in theo thứ tự tăng dần chỉ số trong mảng đã sắp xếp.
// - Nếu không có tập con nào, in ra `-1`.

// VÍ DỤ

// Ví dụ 1
// Input
// 4 8
// 2 4 6 8

// Output
// [2 6]
// [8]

// Ví dụ 2
// Input
// 3 5
// 2 4 6

// Output
// -1


#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], X[100];
bool ok;

void nhap()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ok = false;
}

void Try(int sum, int i, int pos)
{
    for (int j = pos; j < n; j++) {
        if (sum + a[j] <= k) {
            sum += a[j];
            X[i] = a[j];
            if (sum == k) {
                ok = true;
                cout << "[";
                for (int t = 0; t <= i; t++) {
                    cout << X[t];
                    if (t == i) {
                        cout << "]" << endl;
                    } else {
                        cout << " ";
                    }
                }
            } else {
                Try(sum, i + 1, j + 1);
            }
            sum -= a[j];
        }
    }
}

int main()
{
    nhap();
    Try(0, 0, 0); // sum = 0, i bat dau tu 0 la chi so cua tap con X[], j bat dau tu 0 la chi so cua tap cha a[]
    if (ok = false) {
        cout << "-1" << endl;
    }
    return 0;
}