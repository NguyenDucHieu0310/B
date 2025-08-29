#include <bits/stdc++.h>
using namespace std;

bool isTriangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> l(5);
    while (cin >> l[0] >> l[1] >> l[2] >> l[3] >> l[4]) {
        int count = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                for (int k = j + 1; k < 5; ++k) {
                    if (isTriangle(l[i], l[j], l[k])) ++count;
                }
            }
        }
        cout << count << '\n';
    }
}