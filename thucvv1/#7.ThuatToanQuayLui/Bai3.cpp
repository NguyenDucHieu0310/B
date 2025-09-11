// ĐỀ BÀI

// Cho một ma trận vuông nhị phân kích thước n × n (chỉ chứa 0 và 1).  
// Bạn đứng tại ô (1, 1) (góc trên bên trái) và muốn đi đến ô (n, n) (góc dưới bên phải).  

// Quy tắc di chuyển:
// - Có thể di chuyển sang **4 hướng**:
//   - U: lên trên (Up)
//   - D: xuống dưới (Down)
//   - L: sang trái (Left)
//   - R: sang phải (Right)
// - Chỉ được đi qua các ô có giá trị 1.
// - Không được đi lại vào ô đã đi qua (mỗi ô chỉ đi tối đa 1 lần).

// Hãy liệt kê tất cả các đường đi hợp lệ từ (1, 1) đến (n, n).  
// Các đường đi được in theo **thứ tự từ điển tăng dần**.  
// Nếu không có đường đi nào, in ra `-1`.

// INPUT
// - Dòng 1: số nguyên n — kích thước của ma trận.
// - n dòng tiếp theo: mỗi dòng gồm n số nguyên 0 hoặc 1.

// OUTPUT
// - Liệt kê tất cả các đường đi (mỗi đường đi là một chuỗi ký tự gồm U, D, L, R).
// - Nếu không có đường đi nào, in ra -1.

// VÍ DỤ

// Ví dụ 1
// Input
// 4
// 1 0 0 0
// 1 1 0 1
// 1 1 0 0
// 0 1 1 1

// Output
// DRDDRR
// DRDRDR
// DRDRRD
// DDRRDR
// DDRRRD

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

int n;
int a[1001][1001];
vector<string> res;

void nhap()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

int dx[4] = { -1, 0, 0, 1 }; // chi so hang i
int dy[4] = { 0, -1, 1, 0 }; // chi so cot j
string path = "ULRD";

void Try(int i, int j, string s)
{
    if (i == n && j == n) {
        res.push_back(s);
        return;
    }
    // duyet 4 o xung quanh
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1) {
            a[i1][j1] = 0;
            s += path[k];
            Try(i1, j1, s);
            a[i1][j1] = 1;
            s.pop_back();
        }
    }
}

int main()
{
    cin >> n;
    nhap();
    string s = "";
    a[1][1] = 0; // tranh truong hop quay lai o ban dau
    Try(1, 1, s);
    sort(res.begin(), res.end());
    if (res.size() == 0) {
        cout << -1 << endl;
    } else {
        for (string x : res) {
            cout << x << endl;
        }
    }
    return 0;
}