#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<ll> cp(n + 1, 0);     // số cổ phần (mod)
    vector<ll> extra(n + 1, 0);  // số tiền đã nhận/ghi nhận (mod)
    ll profit = 0;               // tổng lợi nhuận trên mỗi cổ phần (mod)

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            ll x; 
            cin >> p >> x;
            x %= MOD;
            // Khi mua thêm x cổ phần, tránh trả lợi nhuận đã tích lũy trước đó cho cổ phần mới
            // nên tăng extra[p] tương ứng: extra += x * profit
            cp[p] = (cp[p] + x) % MOD;
            extra[p] = (extra[p] + (x * profit) % MOD) % MOD;
        } 
        else if (t == 2) {
            ll nhan;
            cin >> nhan;
            nhan %= MOD;
            profit = (profit + nhan) % MOD;
        } 
        else if (t == 3) {
            int p;
            cin >> p;
            ll total = ( (cp[p] * profit) % MOD - extra[p] ) % MOD;
            if (total < 0) total += MOD;
            cout << total << '\n';
            // sau khi rút, đánh dấu đã nhận (đặt extra = cp*profit thực tế)
            extra[p] = (extra[p] + total) % MOD;
        }
    }
    return 0;
}
