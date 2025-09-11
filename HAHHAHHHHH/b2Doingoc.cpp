#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--){

    ll n;
    cin>>n;
    vector<ll> v(n);
    ll count =0, temp;

    for(int i=0; i<n; i++) cin>>v[i];

    for(int i=0; i<n; i++){
        cin>>temp;
        count+=(v[i]-temp)*pow(2,i);
    }
    if(count>=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
    
    return 0;
}