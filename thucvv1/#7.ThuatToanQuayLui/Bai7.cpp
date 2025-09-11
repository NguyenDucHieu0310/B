// ĐỀ BÀI

// Bài toán 8-Queens có trọng số:  
// Cho một bàn cờ kích thước 8 × 8. Mỗi ô trên bàn cờ có một giá trị nguyên a[i][j].  
// Hãy đặt 8 quân hậu lên bàn cờ sao cho:  
// - Không có 2 quân hậu nào tấn công lẫn nhau (không cùng hàng, cột, đường chéo chính, đường chéo phụ).  
// - Tổng giá trị các ô mà quân hậu chiếm là lớn nhất.  

// Hãy tính tổng giá trị lớn nhất có thể đạt được.

// INPUT
// - 8 dòng, mỗi dòng gồm 8 số nguyên a[i][j] (1 ≤ i, j ≤ 8).

// OUTPUT
// - Một số nguyên duy nhất là tổng giá trị lớn nhất.

// VÍ DỤ

// Ví dụ 1  
// Input
// 1 1 1 1 1 1 1 1
// 1 2 2 2 2 2 2 1
// 1 2 3 3 3 3 2 1
// 1 2 3 4 4 3 2 1
// 1 2 3 4 4 3 2 1
// 1 2 3 3 3 3 2 1
// 1 2 2 2 2 2 2 1
// 1 1 1 1 1 1 1 1

// Output
// 24


#include <bits/stdc++.h>
using namespace std;

int n = 8, X[101], cot[101], xuoi[101], nguoc[101], ans = 0;
int a[101][101];

void nhap()
{
    memset(cot, 1, sizeof(cot));
    memset(xuoi, 1, sizeof(xuoi));
    memset(nguoc, 1, sizeof(nguoc));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (cot[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
            X[i] = j;
            if (i == n) {
                int sum = 0;
                for (int t = 1; t <= n; t++) {
                    sum += a[t][X[t]]; // X[t] là chỉ số hàng đã gán ở trên;
                }
                ans = max(ans, sum);
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