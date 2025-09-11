#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll solve(ll n ,vector<ll>&v){

    ll c1=0, c2=0;

    for(auto x:v){

        if(x>=2){
            c2++;
            c1+=(x-2);
        }
        else c1++;
    }
    return c1/2+c2/2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    while(m--){
        ll n; cin>>n;
        vector<ll> v(n);
        for(ll i=0; i<n;i++){
            cin>>v[i];
        }
        cout<<solve(n,v)<<endl;

    }
    return 0;
}