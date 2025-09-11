/*
Đề bài:
Cho một mảng n số nguyên, hãy tìm tập con lớn nhất của các số sao cho với mỗi số trong tập, giá trị của nó không nhỏ hơn tổng các số đã chọn trước đó.

Input:
- Dòng 1: Số nguyên n (1 ≤ n ≤ 10^5)
- Dòng 2: n số nguyên a[i] (1 ≤ a[i] ≤ 10^9)

Output:
- Một số nguyên, số lượng phần tử trong tập con lớn nhất thỏa mãn điều kiện.

Ví dụ:

Input:
5
2 3 4 5 6

Output:
3
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
    int dem = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= sum) {
            ++dem;
            sum += a[i];
        }
    }
    cout << dem << endl;
    return 0;
}