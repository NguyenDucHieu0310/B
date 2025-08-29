#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool check(double mid, int f, vector<double>& pie) {
    int count = 0;
    for(int i=0; i<pie.size(); i++) {
        count += (int)(pie[i]/mid);
    }
    if(count < f+1) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, f;
        cin >> n >> f;
        vector<double> pie(n);
        for(int i=0; i<n; i++) {
            double r;
            cin >> r;
            pie[i] = atan(1)*4*r*r;
        }
        sort(pie.begin(), pie.end(), greater<double>());
        for(auto x:pie) cout<<x<<" ";
        double l = 0, h = pie[0];
        while(h-l > 1e-7) {
            double mid = (l+h)/2;
            if(check(mid, f, pie)) l = mid;
            else h = mid;
        }
        cout << fixed << setprecision(6) << l << endl;
    }
    return 0;
}
