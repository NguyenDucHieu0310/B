#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll mod =1e9+7;

ll power(ll x, ll y) {
    ll res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << power(a, b);
    return 0;
}
