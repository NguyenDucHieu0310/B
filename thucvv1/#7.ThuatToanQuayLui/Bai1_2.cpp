// ĐỀ BÀI

// Cho 3 số nguyên dương n, k, s.  
// Hãy đếm số cách chọn ra k số nguyên phân biệt trong tập {1, 2, ..., n} sao cho tổng của chúng bằng s.

// INPUT
// - Một dòng gồm 3 số nguyên n, k, s.

// OUTPUT
// - In ra số lượng cách chọn thỏa mãn điều kiện.

// VÍ DỤ

// Ví dụ 1
// Input
// 9 3 23

// Output
// 1
// Giải thích:
// Chỉ có một bộ {7, 8, 8} nhưng do các số phải phân biệt nên bộ hợp lệ duy nhất là {7, 8, 9} với tổng = 24 → không hợp lệ.
// Với n=9, k=3, s=23 chỉ có duy nhất bộ {6, 8, 9}.

// Ví dụ 2
// Input
// 9 3 22

// Output
// 2
// Giải thích:
// Các bộ thỏa mãn:
// - {5, 8, 9}
// - {6, 7, 9}


#include <bits/stdc++.h>
using namespace std;

int n, k, s, X[1001], ans = 0;

// cach 2: su dung to hop, sinh ra tat cac cac truong hop va tinh tong nếu == s thì tăng ans

void Try(int i)
{
    for (int j = X[i - 1] + 1; j <= n - k + i; j++) {
        X[i] = j;
        if (i == k) {
            int sum = 0;
            for (int h = 1; h <= k; h++) {
                sum += X[h];
            }
            if (sum == s) {
                ans++;
            }
        } else {
            Try(i + 1);
        }
    }
}

int main()
{
    cin >> n >> k >> s;
    Try(1);
    cout << ans << endl;
    return 0;
}