// ## Đề bài
// Cho một dãy số nguyên `a[1..n]`. Hãy tìm tổng lớn nhất của một **dãy con tăng dần** trong dãy đã cho.

// ## Input
// - Dòng 1: Số nguyên `n` (1 ≤ n ≤ 10^5)  
// - Dòng 2: n số nguyên a[i] (|a[i]| ≤ 10^9)

// ## Output
// - Một số nguyên duy nhất là tổng lớn nhất của một dãy con tăng.

// ## Ví dụ

// ### Input
// 6  
// 1 101 2 3 100 4  

// ### Output
// 106

// (Giải thích: Dãy con tăng có tổng lớn nhất là 1 + 2 + 3 + 100 = 106)


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    long long sum[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i] = a[i]; // tổng lớn nhất của dãy con tăng dần kết thúc ở chỉ số i
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                sum[i] = max(sum[i], sum[j] + a[i]);
            }
        }
    }
    cout << *max_element(sum, sum + n) << endl;
    return 0;
}