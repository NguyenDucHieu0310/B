// ## Đề bài
// Cho N loại tiền với các mệnh giá khác nhau được lưu trong mảng `a[]`.  
// Hãy tính **số cách đổi được số tiền X** sử dụng bất kỳ số tờ tiền nào (có thể sử dụng nhiều tờ cùng mệnh giá). Kết quả in ra **mod 10^9 + 7**.

// ## Input
// - Dòng 1: Hai số nguyên N và X (1 ≤ N ≤ 100, 1 ≤ X ≤ 10^5)  
// - Dòng 2: N số nguyên a[1..N] (1 ≤ a[i] ≤ 10^5) – mệnh giá tiền

// ## Output
// - Một số nguyên: số cách đổi được số tiền X modulo 10^9 + 7

// ## Ví dụ

// ### Input
// 3 5  
// 1 2 5

// ### Output
// 4

// (Giải thích: 4 cách là: 1+1+1+1+1, 1+1+1+2, 1+2+2, 5)


#include <bits/stdc++.h>
using namespace std;

// nguoc lai voi bai 17:
// voi moi gia tri thi xet tat ca ca dong xu doi voi gia tri do
// dao nguoc 2 vong for

int main()
{
    int n, X;
    cin >> n >> X;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long res[X + 1] = { 0 };
    res[0] = 1;
    for (int i = 0; i <= X; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= a[j]) {
                res[i] += res[i - a[j]];
                res[i] %= (int)(1e9 + 7);
            }
        }
    }
    cout << res[X] % (int)(1e9 + 7) << endl;
    return 0;
}