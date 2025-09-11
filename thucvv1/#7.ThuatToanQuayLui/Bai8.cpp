// ĐỀ BÀI

// Cho một mảng gồm n số nguyên dương a[1..n] và một số nguyên k.  
// Hãy kiểm tra xem có thể chia mảng này thành k tập con sao cho:  
// - Mỗi phần tử chỉ thuộc đúng 1 tập con.  
// - Tổng các phần tử trong mỗi tập con đều bằng nhau.  

// Nếu có thể chia, in ra 1. Ngược lại, in ra 0.

// INPUT
// - Dòng 1: hai số nguyên n và k (1 ≤ n ≤ 20, 1 ≤ k ≤ n).  
// - Dòng 2: n số nguyên dương a[i].

// OUTPUT
// - In ra 1 nếu có thể chia thành k tập con có tổng bằng nhau.  
// - In ra 0 nếu không thể.

// VÍ DỤ

// Ví dụ 1  
// Input
// 5 3
// 2 1 4 5 6

// Output
// 1

// Giải thích: Có thể chia thành 3 tập con:
// - {1, 5}, {2, 4}, {6} mỗi tập con có tổng = 6.

// Ví dụ 2  
// Input
// 5 3
// 2 1 5 5 6

// Output
// 0

// Giải thích: Tổng mảng là 19, không chia hết cho 3 nên không thể chia thành 3 tập con bằng nhau.


#include <bits/stdc++.h>
using namespace std;

int n, k, sum = 0, a[50];
int ans = 0; // ket qua
bool daXet[50];

void nhap()
{
    memset(daXet, false, sizeof(daXet)); // false la chua su dung
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void Try(int cnt, int s)
{
    if (cnt == k) {
        ans = 1;
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (daXet[j] == false && s + a[j] <= sum) {
            s += a[j];
            daXet[j] = true; // danh dau da su dung
            if (s == sum) {
                Try(cnt + 1, 0); // dem tang them 1 tap con
            } else {
                Try(cnt, s); // tim tiep phan tu cho tap con hien tai
            }
            daXet[j] = false; // tra lai ve chua su dung
            s -= a[j];
        }
    }
}

int main()
{
    nhap();
    if (sum % k != 0) {
        cout << "0" << endl;
    } else {
        sum /= k; // sum luc nay la tong cua 1 mang con
        Try(0, 0);
        cout << ans << endl;
    }
    return 0;
}