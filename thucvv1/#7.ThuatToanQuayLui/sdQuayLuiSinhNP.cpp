// ### ĐỀ BÀI: SINH XÂU NHỊ PHÂN ĐỘ DÀI N

// Cho số nguyên dương **n**. Hãy in ra tất cả các xâu nhị phân độ dài `n`.

// #### Input  
// - Một số nguyên `n` (1 ≤ n ≤ 15).

// #### Output  
// - In ra tất cả các xâu nhị phân có độ dài `n`.  
// - Mỗi xâu trên một dòng.  
// - Thứ tự in từ trái sang phải.

// ---

// #### Ví dụ  

// Input
// 3

// Output
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111


#include <bits/stdc++.h>
using namespace std;
int X[1001], n;

void Try(int i)
{
    for (int j = 0; j <= 1; j++) {
        X[i] = j;
        if (i == n) {
            for (int k = 1; k <= n; k++) {
                cout << X[k];
            }
            cout << endl;
        } else {
            Try(i + 1);
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
    return 0;
}