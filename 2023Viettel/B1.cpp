#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> seats(n);
    for (int i = 0; i < n; ++i) {
        cin >> seats[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m - 3; ++j) {
            if (seats[i][j] == '.' && seats[i][j+1] == '.' && seats[i][j+2] == '.') {
                cout << (i+1) << " " << (j+1) << endl;
                return 0;
            }
        }
    }
    return 0;
}