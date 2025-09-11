#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool found = false;

        for (int i = 0; i + 2 < n; i++) {
            int cntU = 0, cntI = 0;
            for (int j = 0; j < 3; j++) {
                if (s[i+j] == 'U') cntU++;
                else cntI++;
            }
            if (cntU > 0 && cntI > 0 && (cntU >= 2*cntI || cntI >= 2*cntU)) {
                cout << "Yes " << i+1 << " " << i+3 << "\n";
                found = true;
                break;
            }
        }

        if (!found) cout << "No\n";
    }

    return 0;
}
