/*
Đề bài:
Cho một mảng a[] gồm n số nguyên từ 1 đến n và một mảng b[] gồm n-1 số nguyên được tạo ra bằng cách xóa đi một số trong a[]. Hãy tìm vị trí (1-based) của số bị xóa.

Input:
- Dòng 1: Số nguyên n (2 ≤ n ≤ 10^5)
- Dòng 2: n số nguyên của mảng a[]
- Dòng 3: n-1 số nguyên của mảng b[]

Output:
- Một số nguyên: vị trí (1-based) của phần tử bị xóa

Ví dụ:

Input:
5
1 2 3 4 5
1 2 4 5

Output:
3
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n - 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    int i = 0;
    while (i < n - 1) {
        if (a[i] != b[i]) {
            cout << i + 1 << endl;
            return 0;
        }
        i++;
    }
    return 0;
}