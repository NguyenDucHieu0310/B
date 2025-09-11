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
// Chỉ có 1 bộ {6, 8, 9} có tổng = 23.

// Ví dụ 2
// Input
// 9 3 22

// Output
// 2
// Giải thích:
// Có 2 bộ thỏa mãn:
// - {5, 8, 9}
// - {6, 7, 9}


#include <bits/stdc++.h>
using namespace std;

int n, k, s, ans = 0;

void Try(int pos, int cnt, int sum)
{
    for (int j = pos; j <= n; j++) {
        if (sum + j <= s) {
            sum += j;
            cnt++;
            if (sum == s && cnt == k) {
                ans++;
            } else {
                Try(j + 1, cnt, sum);
            }
            sum -= j;
            --cnt;
        }
    }
}

int main()
{
    cin >> n >> k >> s;
    Try(0, 0, 1);
    cout << ans << endl;
    return 0;
}