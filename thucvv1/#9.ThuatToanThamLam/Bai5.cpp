/*
Đề bài:
Cho một mảng a gồm n số nguyên. Kiểm tra xem mảng có thể sắp xếp sao cho mỗi phần tử a[i] bằng chính nó hoặc phần tử đối xứng trong mảng khi sắp xếp tăng dần hay không.

Input:
- Dòng 1: số nguyên n (1 ≤ n ≤ 10^5)
- Dòng 2: n số nguyên a[i] (1 ≤ a[i] ≤ 10^9)

Output:
- In "YES" nếu mảng thỏa mãn điều kiện, ngược lại in "NO"

Ví dụ:

Input:
5
1 3 2 3 1

Output:
YES

Input:
4
1 3 2 4

Output:
NO
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
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (!(a[i] == b[i] || a[i] == b[n - i - 1])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}