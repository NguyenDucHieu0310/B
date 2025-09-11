// Đề bài

// Cho hai số nguyên dương được viết dưới dạng chuỗi, trong đó các chữ số 5 và 6 có thể bị nhầm lẫn.
// Hãy tính tổng lớn nhất và nhỏ nhất có thể của hai số này.

// Khi tính tổng nhỏ nhất, coi tất cả 6 là 5.

// Khi tính tổng lớn nhất, coi tất cả 5 là 6.

// Input

// Dòng 1: Hai chuỗi số nguyên a và b (1 ≤ độ dài ≤ 18).

// Output

// Hai số nguyên: tổng lớn nhất và tổng nhỏ nhất.

// Ví dụ
// Input

// 56 65

// Output

// 71 110


#include <bits/stdc++.h>
using namespace std;

long long min_val(string a, string b)
{
    for (char& x : a) {
        if (x == '6') {
            x = '5';
        }
    }
    for (char& x : b) {
        if (x == '6') {
            x = '5';
        }
    }
    return stoll(a) + stoll(b);
}

long long max_val(string a, string b)
{
    for (char& x : a) {
        if (x == '5') {
            x = '6';
        }
    }
    for (char& x : b) {
        if (x == '5') {
            x = '6';
        }
    }
    return stoll(a) + stoll(b);
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << max_val(a, b) << " " << min_val(a, b) << endl;
    return 0;
}