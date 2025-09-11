/*
Đề bài:
Tìm số nguyên dương có d chữ số sao cho tổng các chữ số bằng s và số nguyên đó là nhỏ nhất. Nếu không tồn tại số như vậy, in -1.

Input:
- Dòng 1: Hai số nguyên s d (1 ≤ s ≤ 900, 1 ≤ d ≤ 1000)

Output:
- Số nguyên d chữ số nhỏ nhất có tổng các chữ số bằng s, hoặc -1 nếu không tồn tại.

Ví dụ:

Input:
20 3

Output:
299

Input:
3 2

Output:
12

Input:
50 3

Output:
-1
*/


#include <bits/stdc++.h>
using namespace std;

int a[1001];
int main()
{
    int s, d;
    cin >> s >> d;
    if(9 * d < s || (d >= 2 && s <= 1)){
        cout << -1 << endl;
        return 0;
    }
    int s1 = s - 1;
    int i = d - 1;
    while (s1 >= 9 && i >= 0) {
        a[i] = 9;
        s1 -= 9;
        i--;
    }
    if (i > 0) {
        a[i] = s1;
        s1 = 0;
    }
    a[0] = 1 + s1;
    for (int i = 0; i < d; i++) {
        cout << a[i];
    }
}