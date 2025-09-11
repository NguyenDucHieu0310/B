// ĐỀ BÀI

// Cho một ma trận vuông nhị phân kích thước n × n (chỉ chứa 0 và 1).  
// Bạn đứng tại ô (1, 1) (góc trên bên trái) và muốn đi đến ô (n, n) (góc dưới bên phải).  

// Quy tắc di chuyển:
// - Chỉ được đi xuống (D — Down) hoặc đi sang phải (R — Right).
// - Chỉ được đi qua các ô có giá trị 1.

// Hãy liệt kê tất cả các đường đi hợp lệ từ (1, 1) đến (n, n) theo thứ tự duyệt từ trái sang phải, trên xuống dưới.  
// Nếu không có đường đi nào, in ra -1.

// INPUT
// - Dòng 1: số nguyên n — kích thước của ma trận.
// - n dòng tiếp theo: mỗi dòng gồm n số nguyên 0 hoặc 1.

// OUTPUT
// - Liệt kê tất cả các đường đi (mỗi đường đi là một chuỗi ký tự gồm D và R).
// - Nếu không có đường đi nào, in ra -1.

// VÍ DỤ

// Ví dụ 1
// Input
// 4
// 1 0 0 0
// 1 1 0 1
// 0 1 0 0
// 1 1 1 1

// Output
// DDRDRR
// DRDDRR

// Ví dụ 2
// Input
// 4
// 1 0 0 0
// 1 1 0 1
// 0 0 0 0
// 1 1 1 1

// Output
// -1


#include <bits/stdc++.h>
using namespace std;

int n, a[1001][1001];
bool ok = false;

void nhap()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

void Try(int i, int j, string s)
{
    if (i == n && j == n) {
        cout << s << endl;
        ok = true;
        return;
    }
    if (i + 1 <= n && a[i + 1][j] == 1) {
        s += "D";
        a[i + 1][j] = 0;
        Try(i + 1, j, s);
        s.pop_back();
        a[i + 1][j] = 1;
    }
    if (j + 1 <= n && a[i][j + 1] == 1) {
        s += "R";
        a[i][j + 1] = 0;
        Try(i, j + 1, s);
        s.pop_back();
        a[i][j + 1] = 1;
    }
}

int main()
{
    cin >> n;
    nhap();
    string s = "";
    Try(1, 1, s);
    if (ok == false) {
        cout << "-1" << endl;
    }
    return 0;
}