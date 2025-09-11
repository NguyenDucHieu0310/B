/*
Đề bài:
Cho N số nguyên dương, mỗi lần bạn có thể chọn hai số bất kỳ, cộng chúng lại và thêm kết quả vào danh sách, đồng thời tính tổng cộng các lần cộng đó. Lặp lại đến khi chỉ còn một số trong danh sách. Hãy tính tổng cộng các lần cộng modulo 1e9 + 7.

Input:
- Dòng 1: số nguyên n (1 ≤ n ≤ 10^5)
- Dòng 2: n số nguyên dương: a_1, a_2, ..., a_n (1 ≤ a_i ≤ 10^9)

Output:
- Một số nguyên: tổng cộng các lần cộng modulo 1e9 + 7.

Ví dụ:

Input:
4
1 2 3 4

Output:
26

Giải thích:
- Bước 1: chọn 4 và 3 → sum = 7, tổng = 7
- Bước 2: chọn 7 và 2 → sum = 9, tổng = 7 + 9 = 16
- Bước 3: chọn 9 và 1 → sum = 10, tổng = 16 + 10 = 26
- Kết quả = 26
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = (int)1e9 + 7;

int main()
{
    priority_queue<ll> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    long long ans = 0;
    while (pq.size() > 1) {
        ll top1 = pq.top();
        pq.pop();
        ll top2 = pq.top();
        pq.pop();
        ll sum = top1 + top2;
        ans += (sum % MOD);
        ans %= MOD;
        pq.push(sum);
    }
    cout << ans << endl;
    return 0;
}