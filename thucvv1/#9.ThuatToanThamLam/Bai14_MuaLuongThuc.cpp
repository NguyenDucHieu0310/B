/*
Đề bài:
Một người cần mua lương thực để sử dụng trong s ngày, mỗi ngày cần m đơn vị lương thực. Mỗi ngày chỉ có thể mua tối đa n đơn vị, và mỗi tuần có 1 ngày không thể đi mua. Hãy tính số ngày tối thiểu cần đi mua để đảm bảo đủ lương thực.

Input:
- Dòng 1: Ba số nguyên n s m (1 ≤ n, s, m ≤ 10^5)

Output:
- Một số nguyên: số ngày tối thiểu cần đi mua hoặc -1 nếu không đủ khả năng mua.

Ví dụ:

Input:
16 12 2

Output:
2

Input:
2 7 3

Output:
-1
*/



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, m; // n: so luong thuc co the mua trong 1 ngay, s: so ngay can su dung luong thuc, m la so luong thuc can su dung trong 1 ngay
    cin >> n >> s >> m;
    int s1 = s - (s / 7); // tinh so ngay co the di mua luong thuc
    int res1 = s1 * n; // so luong thuc toi da co the mua
    int res2 = s * m; // so luong thuc can su dung
    if (s * m > s1 * n) {
        cout << "-1" << endl;
        return 0;
    } else {
        for (int i = 1; i <= s1; i++) {
            if (n * i >= res2) {
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}