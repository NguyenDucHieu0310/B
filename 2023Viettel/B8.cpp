#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Block {
    vector<int> v; // sorted values
    ll cost;       // sum |x - median|
    int median;
    Block(int x=0) {
        v = {x};
        cost = 0;
        median = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<Block> st;
    st.reserve(n);
    for (int i = 0; i < n; ++i) {
        st.emplace_back(a[i]);
        // merge while violation of nondecreasing medians
        while (st.size() >= 2) {
            int m = st.size();
            if (st[m-2].median <= st[m-1].median) break;
            // merge last two blocks
            vector<int> merged;
            merged.reserve(st[m-2].v.size() + st[m-1].v.size());
            std::merge(st[m-2].v.begin(), st[m-2].v.end(),
                       st[m-1].v.begin(), st[m-1].v.end(),
                       back_inserter(merged));
            int sz = (int)merged.size();
            int med = merged[sz/2];
            ll cost = 0;
            for (int x : merged) cost += ll(abs(x - med));
            st.pop_back();
            st.pop_back();
            Block nb;
            nb.v.swap(merged);
            nb.median = med;
            nb.cost = cost;
            st.push_back(std::move(nb));
        }
    }

    ll ans = 0;
    for (auto &b : st) ans += b.cost;
    cout << ans << '\n';
    return 0;
}