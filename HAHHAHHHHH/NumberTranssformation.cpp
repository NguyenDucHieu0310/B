#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        if (m % n != 0) {
            cout << -1 << "\n";
            continue;
        }

        ll k = m / n;
        vector<ll> ops;
        bool ok = true;

        while (n < m) {
            ll g = gcd(n, k); // phần chung lớn nhất giữa n và k
            if (g == 1) {     // không thể tăng thêm
                ok = false;
                break;
            }
            n *= g;           // nhân thêm vào n
            k /= g;           // giảm bớt phần còn lại
            ops.push_back(g);
        }

        if (!ok || n != m) {
            cout << -1 << "\n";
        } else {
            cout << ops.size();
            for (ll x : ops) cout << " " << x;
            cout << "\n";
        }
    }
    return 0;
}
