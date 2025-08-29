#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int64 k, m;
    if (!(cin >> n >> k >> m)) return 0;
    vector<int64> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    
    vector<int64> pref(n+1, 0);
    int64 minPref = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1] + a[i];
        minPref = min(minPref, pref[i]);
    }
    int64 S = pref[n];
    int64 T = 0;
    if (minPref < 0) T = -minPref; 

    int pos = 1;
    int64 x = k;
    int64 turns = 0;

    while (true) {
        
        if (a[pos] >= 0) {
            x += a[pos];
        } else {
            x = max<int64>(0, x + a[pos]);
        }
        ++turns;
        if (x <= m) {
            cout << turns << '\n';
            return 0;
        }
        
        ++pos;
        if (pos > n) pos = 1;

        
        if (pos == 1) {
            if (x >= T) {
                if (S > 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                if (S == 0) {
                    
                    int found = -1;
                    for (int j = 1; j <= n; ++j) {
                        if (x + pref[j] <= m) { found = j; break; }
                    }
                    if (found != -1) {
                        turns += (found - 0); 
                        cout << turns << '\n';
                        return 0;
                    } else {
                        cout << -1 << '\n';
                        return 0;
                    }
                }
                
                int64 Sneg = -S; 
                
                int64 numerator = x + minPref - m; 
                int64 t_needed = 0;
                if (numerator > 0) {
                    t_needed = (numerator + Sneg - 1) / Sneg;
                }
                
                int64 tmax = 0;
                if (x >= T) {
                    tmax = (x - T) / Sneg;
                }
                if (t_needed <= tmax) {
                    
                    int64 Xstart = x - t_needed * Sneg;
                    
                    int found = -1;
                    for (int j = 1; j <= n; ++j) {
                        if (Xstart + pref[j] <= m) { found = j; break; }
                    }
                    if (found == -1) {
                        
                        
                    } else {
                        turns += t_needed * (int64)n;
                        turns += found;
                        cout << turns << '\n';
                        return 0;
                    }
                } else {
                    
                    if (tmax > 0) {
                        x -= tmax * Sneg;
                        turns += tmax * (int64)n;
                    }
                    
                }
            }
        }
        
    }

    return 0;
}