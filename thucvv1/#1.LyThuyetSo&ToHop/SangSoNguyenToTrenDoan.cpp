#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)1e7;

void sang(int l, int r)
{
    int prime[r - l + 1];
    for (int i = 0; i <= r - l; i++) {
        prime[i] = 1;
    }

    for (int i = 2; i <= r - l; i++) {
        if (prime[i]) {
            cout << i << endl;
            for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) {
                prime[j - l] = 0;
            }
        }
    }

    for (int i = max(2, l); i <= r; i++) {
        if (prime[i - l]) {
            cout << i << " ";
        }
    }
}

int main()
{
    sang(1, 100);
    return 0;
}