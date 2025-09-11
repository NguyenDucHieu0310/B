// ## Đề bài
// Cho N loại tiền với các mệnh giá khác nhau được lưu trong mảng `a[]`.  
// Hãy tính **số cách đổi được số tiền X** sử dụng bất kỳ số tờ tiền nào (có thể sử dụng nhiều tờ cùng mệnh giá). Kết quả in ra **mod 10^9 + 7**.  
// Lưu ý: Trong bài này, **với mỗi mệnh giá, ta xét tuần tự từng loại tiền và cập nhật tổng**.

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

// res[i]: so cach lua chon cac dong xu sao cho no co tong = i

int main()
{
    int n, X;
    cin >> n >> X;
    int a[n];
    long long res[X + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= X; i++) {
        res[i] = 0;
    }
    res[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= X; j++) {
            if (j >= a[i]) {
                res[j] += res[j - a[i]];
                res[j] %= (int)(1e9 + 7);
            }
        }
    }
    cout << res[X] % (int)(1e9 + 7) << endl;
    return 0;
}