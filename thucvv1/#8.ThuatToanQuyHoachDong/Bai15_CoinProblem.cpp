// ## Đề bài
// Ngân hàng XYZ có `N` loại tiền với các mệnh giá khác nhau được lưu trong mảng `c[]`.  
// Hãy tìm cách đổi số tiền `S` sao cho **số tờ tiền sử dụng là ít nhất**. Nếu không đổi được, in `-1`.

// ## Input
// - Dòng 1: Hai số nguyên `N` và `S` (1 ≤ N ≤ 100, 1 ≤ S ≤ 10^5)  
// - Dòng 2: N số nguyên c[1..N] (1 ≤ c[i] ≤ 10^5) – mệnh giá tiền

// ## Output
// - Một số nguyên: số tờ tiền ít nhất để đổi số tiền S, hoặc -1 nếu không đổi được.

// ## Ví dụ

// ### Input
// 3 11  
// 1 5 7

// ### Output
// 3

// (Giải thích: Có thể dùng các tờ tiền 5 + 5 + 1 = 11, tổng 3 tờ)

// ngan hang xyz co N to tien menh gia khac nhau duoc luu vao mang c[], hay tim cach doi so tien S sao cho so to tien la it nhat;
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, S;
    cin >> n >> S;
    vector<int> cnt(S + 1, 1e9);
    cnt[0] = 0;
    int c[n]; // số tờ tiền tối thiểu để có thể đổi số tiền là i
    // c[j] : cnt[i - c[j]];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= S; j++) {
            if (j >= c[i]) { // không xét số tiền nhỏ hơn mệnh giá tờ tiền đang xét
                cnt[j] = min(cnt[j], cnt[j - c[i]] + 1);
            }
        }
    }
    if (cnt[S] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << cnt[S] << endl;
    }
    return 0;
}