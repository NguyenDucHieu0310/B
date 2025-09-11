// ĐỀ BÀI

// Cho một mảng gồm n số nguyên dương a[1..n].  
// Hãy kiểm tra xem có thể chia mảng thành 2 tập con có tổng bằng nhau hay không.  

// Nếu có thể chia được, in ra 1. Nếu không, in ra 0.

// INPUT
// - Dòng 1: số nguyên n (1 ≤ n ≤ 30).  
// - Dòng 2: n số nguyên dương a[i].

// OUTPUT
// - In ra 1 nếu có thể chia thành 2 tập con có tổng bằng nhau.  
// - Ngược lại in ra 0.

// VÍ DỤ

// Ví dụ 1  
// Input
// 4
// 1 5 11 5

// Output
// 1

// Giải thích: Có thể chia thành {1, 5, 5} và {11} đều có tổng = 11.

// Ví dụ 2  
// Input
// 3
// 1 2 5

// Output
// 0

// Giải thích: Tổng mảng = 8 (chẵn), nhưng không thể chia thành 2 tập con có tổng bằng nhau.


#include <bits/stdc++.h>
using namespace std;

int n, sum = 0, a[1001], x[1001], ok;

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void Try(int i, int pos, int s)
{
    if(ok){
        return;
    }
    for(int j = pos; j <= n; j++){
        if(s + a[j] <= sum){
            s += a[j];
            if(s == sum){
                ok = 1;
            } else {
                Try(i + 1, j + 1, s);
            }
            s -= a[j];
        }
    }
}

int main()
{
    nhap();
    if(sum % 2 != 0){
        cout << "0" << endl;
    } else {
        sum /= 2;
        Try(1, 1, 0);
        cout << ok << endl;
    }
    return 0;
}