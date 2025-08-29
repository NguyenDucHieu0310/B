#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Handle infinite ratios when a[i] == 0 and b[i] > 0
    bool has_inf = false;
    for (int i = 0; i < n; ++i) if (a[i] == 0 && b[i] > 0) has_inf = true;
    if (has_inf) {
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (a[i] == 0 && b[i] > 0) ans.push_back(i+1);
        cout << ans.size() << "\n";
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << "\n";
        return 0;
    }

    // Otherwise, find maximum b[i]/a[i] using cross multiplication
    int best = 0;
    for (int i = 1; i < n; ++i) {
        __int128 lhs = (__int128)b[i] * a[best];
        __int128 rhs = (__int128)b[best] * a[i];
        if (lhs > rhs) best = i;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        __int128 lhs = (__int128)b[i] * a[best];
        __int128 rhs = (__int128)b[best] * a[i];
        if (lhs == rhs) ans.push_back(i+1);
    }
    cout << ans.size() << "\n";
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}