// ĐỀ BÀI

// Cho một dãy gồm n số nguyên dương a[1..n].  
// Hãy liệt kê tất cả các dãy con (subsequence) có độ dài ≥ 2 sao cho các phần tử trong dãy con đó được sắp xếp tăng dần theo chỉ số.  
// Kết quả in ra theo thứ tự từ điển tăng dần.

// INPUT
// - Dòng 1: số nguyên n (1 ≤ n ≤ 20).  
// - Dòng 2: n số nguyên dương a[i].

// OUTPUT
// - Mỗi dòng là một dãy con thỏa mãn điều kiện.  
// - Các dãy con được in theo thứ tự từ điển.

// VÍ DỤ

// Ví dụ 1  
// Input
// 4
// 6 3 7 11

// Output
// 3 7 
// 3 11 
// 3 7 11 
// 6 7 
// 6 11 
// 6 7 11 
// 7 11 

// Giải thích: Tất cả các dãy con có độ dài ≥ 2 và tăng dần theo chỉ số được liệt kê.

// Ví dụ 2  
// Input
// 3
// 5 4 3

// Output
// (Không có dãy con nào thỏa mãn)


#include <bits/stdc++.h>
using namespace std;

int n, a[101], X[101];
vector<string> ans;

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void Try(int i, int pos)
{
    for (int j = pos; j <= n; j++) {
        if (a[j] > X[i - 1]) {
            X[i] = a[j];
            if (i >= 2) {
                string tmp = "";
                for (int t = 1; t <= i; t++) {
                    tmp += to_string(X[t]) + " ";
                }
                ans.push_back(tmp);
            } 
            Try(i + 1, j + 1);
        }
    }
}

int main()
{
    nhap();
    Try(1, 1);
    sort(ans.begin(), ans.end());
    for (string x : ans) {
        cout << x << endl;
    }
    return 0;
}