// /d:/Algorithm/VPC2023/B2.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Event {
    ll x;
    int type; // 0 = supplier, 1 = household
    ll d; // demand for household, ignored for supplier
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        ll c;
        int m, n;
        cin >> c >> m >> n;
        vector<Event> ev;
        ev.reserve(m + n);
        for (int i = 0; i < m; ++i) {
            ll s; cin >> s;
            ev.push_back({s, 0, 0});
        }
        for (int i = 0; i < n; ++i) {
            ll x, d; cin >> x >> d;
            ev.push_back({x, 1, d});
        }
        sort(ev.begin(), ev.end(), [](const Event &a, const Event &b){
            return a.x < b.x;
        });
        ll cur = c;
        ll ans = 0;
        for (auto &e : ev) {
            if (e.type == 0) {
                cur = c;
            } else {
                if (cur >= e.d) {
                    ans += e.d;
                    cur -= e.d;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}