/*
ĐỀ BÀI: CHỌN PHẦN TỬ KHÔNG KỀ NHAU CÓ TỔNG LỚN NHẤT

Cho dãy số nguyên a[] gồm n phần tử. 
Hãy chọn ra một tập hợp các phần tử sao cho:
- Không có hai phần tử nào đứng cạnh nhau trong dãy ban đầu.
- Tổng giá trị các phần tử được chọn là lớn nhất.

Input:
- Dòng 1: Số nguyên n (1 ≤ n ≤ 10^5).
- Dòng 2: n số nguyên a[i] (|a[i]| ≤ 10^9).

Output:
- Một số nguyên duy nhất là tổng lớn nhất có thể đạt được.

Ví dụ:

Input
5
3 2 7 10 12

Output
22

(Giải thích: Chọn 3 + 7 + 12 = 22).
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
    long long sum[n + 1];
    sum[0] = a[0];
    sum[1] = max(a[1], a[0]);
    for (int i = 2; i < n; i++) {
        sum[i] = max(sum[i - 1], sum[i - 2] + a[i]);
    }
    cout << sum[n - 1] << endl;
    return 0;
}