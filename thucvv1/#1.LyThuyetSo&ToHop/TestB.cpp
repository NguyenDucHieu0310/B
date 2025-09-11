#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    int tc = 1;

    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;

        long long cnt = 0;
        for (long long t = 1;; ++t) {
            long long x  = t * (t + 1) / 2;
            long long v  = x + 1;
            if (v >= b) break; 
            if (v <= a)  continue;

            long long s = static_cast<long long>(std::sqrt((long double)v));
            if (s * s == v) ++cnt;
        }
        cout << "Case " << tc++ << ": " << cnt << '\n';
    }
    return 0;
}
