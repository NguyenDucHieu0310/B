#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--){
        long long n, x;
        cin>>n>>x;
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(), a.end());

        long long res=n;

        while(res>0&&x*res<a[res-1]) res--;
        cout<<res<<endl;

    }
    
    return 0;
}