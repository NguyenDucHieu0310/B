// ĐỀ BÀI

// Bài toán N-Queens:  
// Cho một bàn cờ kích thước n × n. Hãy đặt n quân hậu lên bàn cờ sao cho:  
// - Không có 2 quân hậu nào tấn công lẫn nhau (không cùng hàng, cột, đường chéo chính, đường chéo phụ).  

// Hãy đếm số cách sắp xếp hợp lệ.

// INPUT
// - Một số nguyên n (1 ≤ n ≤ 15).

// OUTPUT
// - Một số nguyên duy nhất: số cách đặt n quân hậu thỏa mãn điều kiện.

// VÍ DỤ

// Ví dụ 1  
// Input
// 4

// Output
// 2

// Giải thích: Có 2 cách đặt 4 quân hậu trên bàn cờ 4×4.

// Ví dụ 2  
// Input
// 1

// Output
// 1


#include <bits/stdc++.h>
using namespace std;

int n, X[101], cot[101], xuoi[101], nguoc[101], ans = 0;

void nhap()
{
    cin >> n;
    memset(cot, 1, sizeof(cot));
    memset(xuoi, 1, sizeof(xuoi));
    memset(nguoc, 1, sizeof(nguoc));
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (cot[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
            X[i] = j;
            if (i == n) {
                ++ans;
            } else {
                Try(i + 1);
            }
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
        }
    }
}

int main()
{
    nhap();
    Try(1);
    cout << ans << endl;
    return 0;
}