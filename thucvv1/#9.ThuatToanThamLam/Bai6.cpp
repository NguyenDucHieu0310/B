/*
Đề bài:
Cho hai mảng a và b cùng độ dài n. Tính tổng P = a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1] sao cho P lớn nhất có thể.

Input:
- Dòng 1: số nguyên n (1 ≤ n ≤ 10^5)
- Dòng 2: n số nguyên a[i] (1 ≤ a[i] ≤ 10^9)
- Dòng 3: n số nguyên b[i] (1 ≤ b[i] ≤ 10^9)

Output:
- Một số nguyên P là tổng lớn nhất có thể.

Ví dụ:

Input:
3
1 3 2
4 1 2

Output:
13

Giải thích:
Sắp xếp cả hai mảng giảm dần: a = [3,2,1], b = [4,2,1] → P = 3*4 + 2*2 + 1*1 = 13
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long P = 0;
    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    for (int i = 0; i < n; i++) {
        P += 1ll * a[i] * b[i];
    }
    cout << P << endl;
    return 0;
}