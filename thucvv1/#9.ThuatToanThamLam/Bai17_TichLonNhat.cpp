/*
Đề bài:
Cho một mảng n số nguyên, hãy tìm tích lớn nhất có thể của hai hoặc ba phần tử trong mảng.

Input:
- Dòng 1: Số nguyên n (3 ≤ n ≤ 10^5)
- Dòng 2: n số nguyên a[i] (-10^9 ≤ a[i] ≤ 10^9)

Output:
- Một số nguyên, tích lớn nhất có thể tạo ra từ hai hoặc ba phần tử bất kỳ của mảng.

Ví dụ:

Input:
5
-10 -10 5 2 3

Output:
500
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long x1 = 1ll * a[n - 1] * a[n - 2];
    long long x2 = 1ll * a[0] * a[1];
    long long x3 = 1ll * a[0] * a[1] * a[n - 1];
    long long x4 = 1ll * a[n - 1] * a[n - 2] * a[n - 3];
    cout << max({ x1, x2, x3, x4 }) << endl;
    return 0;
}