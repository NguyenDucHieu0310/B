// ### ĐỀ BÀI: SINH HOÁN VỊ  

// Cho số nguyên **n**. Hãy in ra tất cả các hoán vị của tập số `{1, 2, ..., n}`.  

// #### Input  
// - Một số nguyên `n` (1 ≤ n ≤ 9).  

// #### Output  
// - In ra tất cả các hoán vị của tập `{1..n}`, mỗi hoán vị trên một dòng.  
// - Các số trong hoán vị in liền nhau (không có khoảng trắng).  
// - Thứ tự in theo thứ tự sinh từ trái sang phải.  

// #### Ví dụ  

// **Input**  
// 3

// **Output**  
// 123
// 132
// 213
// 231
// 312
// 321



#include <bits/stdc++.h>
using namespace std;

int n, daxet[1001], X[1001];

void in()
{
    for (int i = 1; i <= n; i++) {
        cout << X[i];
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (daxet[j] == 0) {
            X[i] = j;
            daxet[j] = 1;
            if (i == n) {
                in();
            } else {
                Try(i + 1);
            }
            daxet[j] = 0;
        }
    }
}

int main()
{
    memset(daxet, 0, sizeof(daxet));
    cin >> n;
    Try(1);
    return 0;
}