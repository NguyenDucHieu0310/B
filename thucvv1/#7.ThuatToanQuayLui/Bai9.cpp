// ĐỀ BÀI

// Cho mảng a gồm n số nguyên dương và một số nguyên S.  
// Hãy tìm số lượng phần tử ít nhất trong một tập con của mảng có tổng đúng bằng S.  
// Nếu không tồn tại tập con nào có tổng bằng S thì in ra -1.

// INPUT
// - Dòng 1: hai số nguyên n và S (1 ≤ n ≤ 30, 1 ≤ S ≤ 10^5).  
// - Dòng 2: n số nguyên dương a[i].

// OUTPUT
// - Một số nguyên duy nhất: số phần tử ít nhất trong tập con có tổng bằng S.  
// - Nếu không tồn tại, in ra -1.

// VÍ DỤ

// Ví dụ 1  
// Input
// 5 9
// 3 1 7 5 9

// Output
// 1

// Giải thích: Chỉ cần chọn phần tử 9 → tổng = 9.

// Ví dụ 2  
// Input
// 5 10
// 3 1 7 5 9

// Output
// 2

// Giải thích: Chọn tập con {3, 7} có tổng = 10.

// Ví dụ 3  
// Input
// 5 2
// 3 1 7 5 9

// Output
// -1

// Giải thích: Không tồn tại tập con nào có tổng bằng 2.


#include <bits/stdc++.h>
using namespace std;

int n, k, S, a[1001], X[1001], ans;

void nhap()
{

    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void Try(int i)
{
    for (int j = X[i - 1] + 1; j <= n - k + i; j++) {
        X[i] = j;
        if (i == k) {
            int sum = 0;
            for (int t = 1; t <= k; t++) {
                sum += a[X[t]];
            }
            if (sum == S) {
                ans = k;
                return;
            }
        } else {
            Try(i + 1);
        }
    }
}

int main()
{
    nhap();
    for (int i = 1; i <= n; i++) {
        k = i;
        Try(1);
        if (ans != 0) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}