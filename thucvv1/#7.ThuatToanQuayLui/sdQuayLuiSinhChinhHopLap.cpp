// ### ĐỀ BÀI: SINH TẤT CẢ CÁC DÃY SỐ ĐỘ DÀI K TỪ 1..N  

// Cho hai số nguyên **n** và **k**. Hãy in ra tất cả các dãy có độ dài **k** được tạo thành từ các số trong đoạn `[1..n]`.  

// Các dãy được phép lặp phần tử.  

// #### Input  
// - Hai số nguyên `n, k` (1 ≤ k, n ≤ 10).  

// #### Output  
// - In ra tất cả các dãy có độ dài `k`, mỗi dãy trên một dòng.  
// - Các số trong dãy **in liền nhau** (không có khoảng trắng).  
// - Thứ tự in theo thứ tự sinh từ trái sang phải.  

// #### Ví dụ  

// **Input**  
// 3 2
// **Output**  
// 11
// 12
// 13
// 21
// 22
// 23
// 31
// 32
// 33


#include <bits/stdc++.h>
using namespace std;

int n, k, X[1001];

void in()
{
    for (int i = 1; i <= k; i++) {
        cout << X[i];
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        X[i] = j;
        if (i == k) {
            in();
        } else {
            Try(i + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    Try(1);
    return 0;
}