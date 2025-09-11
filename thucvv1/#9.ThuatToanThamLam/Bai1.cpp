// ## Đề bài
// Ngân hàng XYZ có 10 loại tiền mệnh giá: `1000, 500, 200, 100, 50, 20, 10, 5, 2, 1`.  
// Cho một số tiền `n`. Hãy tìm số tờ tiền ít nhất để đổi được số tiền `n`.

// ## Input
// - Dòng 1: Số nguyên `n` (1 ≤ n ≤ 10^6)

// ## Output
// - Một số nguyên: số tờ tiền ít nhất để đổi được `n`.

// ## Ví dụ

// ### Input
// 2897

// ### Output
// 7

// (Giải thích: 1000 + 1000 + 500 + 200 + 100 + 50 + 20 + 20 + 5 + 2 = 7 tờ với cách dùng ít nhất)



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = { 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (n >= a[i]) {
            ans += n / a[i];
            n %= a[i];
        }
    }
    cout << ans << endl;
    return 0;
}