#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Solve(int m, int n) {
    vector<vector<int>> a(m, vector<int>(n, 0));
    if (m == 1) {
        if (n % 2 == 1) return a;
        for (int j = 0; j < n; ++j)
            a[0][j] = (j % 2 == 0) ? 1 : 0;
        return a;
    }
    if (n == 1) {
        if (m % 2 == 1) return a;
        for (int i = 0; i < m; ++i)
            a[i][0] = (i % 2 == 0) ? 1 : 0;
        return a;
    }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = ((i + j) % 2 == 0) ? 1 : 0;
    return a;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat = Solve(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}