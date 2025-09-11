// ĐỀ BÀI

// Cho một lưới (ma trận) kích thước n × m. Bạn đứng tại ô (1, 1) (góc trên bên trái) và muốn di chuyển đến ô (n, m) (góc dưới bên phải).  
// Mỗi bước, bạn chỉ được phép đi **xuống dưới** hoặc **sang phải**.  

// Hãy tính xem có bao nhiêu cách đi từ (1, 1) đến (n, m).

// INPUT
// - Dòng 1: hai số nguyên n, m — số hàng và số cột của lưới.
// - Dòng 2..n+1: mỗi dòng gồm m số nguyên (trong code có đọc nhưng không dùng).

// OUTPUT
// - Một số nguyên duy nhất là số cách đi từ (1, 1) đến (n, m).

// VÍ DỤ

// Ví dụ 1  
// Input
// 2 2
// 1 1
// 1 1

// Output
// 2

// Ví dụ 2  
// Input
// 3 3
// 1 1 1
// 1 1 1
// 1 1 1

// Output
// 6



#include <bits/stdc++.h>
using namespace std;

int n, m, a[101][101], ans = 0;

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

void Try(int i, int j)
{
    if (i == n && j == m) {
        ans++;
    }
    if (i + 1 <= n) {
        Try(i + 1, j);
    }
    if (j + 1 <= m) {
        Try(i, j + 1);
    }
}

int main()
{
    nhap();
    Try(1, 1);
    cout << ans << endl;
    return 0;
}