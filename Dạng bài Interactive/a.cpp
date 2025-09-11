#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // Distribute at most 100 queries between both countries
    int max_query = min(100, 2 * n);
    int takeF = min(n, max_query / 2);
    int takeS = min(n, max_query - takeF);

    vector<ll> fin, swe;

    for (int i = 1; i <= takeF; ++i) {
        cout << "F " << i << endl << flush;
        ll v; cin >> v;
        fin.push_back(v);
    }
    for (int i = 1; i <= takeS; ++i) {
        cout << "S " << i << endl << flush;
        ll v; cin >> v;
        swe.push_back(v);
    }

    // Merge to find k-th highest
    int i = 0, j = 0, cnt = 0;
    ll ans = -1;
    while (cnt < k) {
        ll fv = (i < fin.size() ? fin[i] : LLONG_MIN);
        ll sv = (j < swe.size() ? swe[j] : LLONG_MIN);
        if (fv >= sv) {
            ans = fv;
            ++i;
        } else {
            ans = sv;
            ++j;
        }
        ++cnt;
    }
    cout << "! " << ans << endl << flush;
    return 0;
}