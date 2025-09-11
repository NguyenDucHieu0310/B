/*
Đề bài:
Cho một xâu s. Hãy kiểm tra xem có thể sắp xếp lại các ký tự trong xâu sao cho không có hai ký tự giống nhau nào đứng cạnh nhau không.

Input:
- Dòng 1: xâu s gồm các chữ cái (1 ≤ |s| ≤ 10^5)

Output:
- "YES" nếu có thể sắp xếp thỏa mãn
- "NO" nếu không thể

Ví dụ:

Input:
aabb

Output:
YES

Input:
aaab
Output:
NO
*/


#include <bits/stdc++.h>
using namespace std;

// tinh toan thong qua ky tu co tan suat nhieu nhat
int main()
{
    string s;
    cin >> s;
    int cnt[256] = { 0 };
    for (char x : s) {
        cnt[x]++;
    }
    int res = 0;
    for (int i = 0; i < 256; i++) {
        res = max(res, cnt[i]);
    }
    if (res <= s.size() - res + 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}