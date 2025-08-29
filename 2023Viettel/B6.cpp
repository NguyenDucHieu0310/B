#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    unordered_set<string> dict;
    string w;
    int maxlen = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w;
        dict.insert(w);
        if ((int)w.size() > maxlen) maxlen = w.size();
    }
    int q;
    cin >> q;
    string s;
    for (int qi = 0; qi < q; ++qi) {
        cin >> s;
        int L = s.size();
        vector<char> ok(L+1, 0);
        vector<int> prev(L+1, -1);
        ok[0] = 1;
        for (int i = 0; i < L; ++i) {
            if (!ok[i]) continue;
            int lim = min(L, i + maxlen);
            for (int j = i+1; j <= lim; ++j) {
                if (!ok[j]) {
                    if (dict.find(s.substr(i, j - i)) != dict.end()) {
                        ok[j] = 1;
                        prev[j] = i;
                    }
                }
            }
            if (ok[L]) break;
        }
        if (!ok[L]) {
            cout << "-1";
        } else {
            vector<string> parts;
            int cur = L;
            while (cur > 0) {
                int p = prev[cur];
                if (p < 0) break;
                parts.push_back(s.substr(p, cur - p));
                cur = p;
            }
            for (int i = (int)parts.size() - 1; i >= 0; --i) {
                if (i != (int)parts.size() - 1) cout << ' ';
                cout << parts[i];
            }
        }
        if (qi + 1 < q) cout << '\n';
    }
    return 0;
}