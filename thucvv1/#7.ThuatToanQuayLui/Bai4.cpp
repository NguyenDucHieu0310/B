// ĐỀ BÀI

// Cho một mảng gồm n số nguyên dương và một số nguyên k.  
// Hãy liệt kê tất cả các tập con của mảng (các phần tử không lặp lại, theo chỉ số tăng dần) sao cho tổng các phần tử trong tập con đúng bằng k.  

// Nếu không tồn tại tập con nào, in ra không có gì.

// INPUT
// - Dòng 1: hai số nguyên n, k — số phần tử của mảng và giá trị tổng cần tìm.
// - Dòng 2: n số nguyên dương — các phần tử của mảng.

// OUTPUT
// - Mỗi dòng là một tập con có tổng bằng k, in theo định dạng `[x1 x2 ... xt]`.
// - Các tập con được in ra theo thứ tự ngược với thứ tự sinh nhị phân (do đoạn `reverse` trong code).

// VÍ DỤ

// Ví dụ 1
// Input
// 4 8
// 2 4 6 8

// Output
// [8]
// [2 6]

// Ví dụ 2
// Input
// 5 10
// 2 3 5 7 8

// Output
// [2 3 5]
// [2 8]



#include <bits/stdc++.h>
using namespace std;

// su dung sinh tap hop (nhi phan): sinh ra tat ca cac tap con va tinh tong, neu == k thi in ra
int n, k;
string s;
bool check;

vector<vector<int>> ketQua;

void khoiTao()
{
    for (int i = 0; i < n; i++) {
        s += "0";
    }
}

void sinh()
{
    int i = n - 1;
    while (i >= 0 && s[i] == '1') {
        s[i] = '0';
        i--;
    }
    if (i == -1) {
        check = false;
    } else {
        s[i] = '1';
    }
}

int main()
{
    cin >> n >> k;
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b, b + n);
    khoiTao();

    check = true;
    while (check) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                ans += b[i];
            }
        }
        if (ans == k) {
            vector<int> tmp;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '1') {
                    tmp.push_back(b[j]);
                }
            }
            ketQua.push_back(tmp);
        }
        sinh();
    }
    reverse(ketQua.begin(), ketQua.end());
    for (auto it : ketQua) {
        cout << "[";
        for (int i = 0; i < it.size(); i++) {
            cout << it[i];
            if (i != it.size() - 1) {
                cout << " ";
            } else {
                cout << "]";
            }
        }
        cout << endl;
    }
    return 0;
}