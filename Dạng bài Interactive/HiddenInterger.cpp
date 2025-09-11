//problem "test"
//created in 13:26:48 - Sun 07/09/2025
#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
void solve() {
    int l = 1, r = 1e9, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        string s;
        cin >> s;
        if (s == "YES") {
            l = mid + 1;
        }
        else {
            r = mid - 1, ans = mid;
        }
    }
    cout << "! " << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int test = 1;
    while (test--) {
        solve();
    }
}