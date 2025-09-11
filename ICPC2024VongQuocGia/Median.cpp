#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n; long long x;
        cin >> n >> x;
        vector<long long> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        int k = (n - 1) / 2; // median index
        int cntLess = 0, cntGreater = 0, cntX = 0, cntMissing = 0;

        for (int i = 0; i < n; i++) {
            if (b[i] == -1) cntMissing++;
            else if (b[i] < x) cntLess++;
            else if (b[i] > x) cntGreater++;
            else cntX++;
        }

        // nếu không có x và không có ô trống
        if (cntX == 0 && cntMissing == 0) {
            cout << "NO\n";
            continue;
        }

        // điều kiện cần: không có quá nhiều phần tử <x hoặc >x
        if (cntLess > k || cntGreater > k) {
            cout << "NO\n";
            continue;
        }

        // có thể làm được
        cout << "YES\n";

        bool placedX = (cntX > 0); // đã có sẵn x hay chưa

        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                if (!placedX) {
                    b[i] = x;
                    placedX = true;
                } else if (cntLess < k) {
                    b[i] = 0; // nhỏ hơn x
                    cntLess++;
                } else {
                    b[i] = 1000000000; // lớn hơn x
                    cntGreater++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << b[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
