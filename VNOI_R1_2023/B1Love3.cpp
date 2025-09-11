#include<bits/stdc++.h>
using namespace std;

bool solve(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin>>v[i];
    for(int i=1; i<=n;i++)
    if(v[v[v[i]]]==i) return true;
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--){
        bool res=solve();
        if(res) cout<<"<3"<<endl;
        else cout<<"</3"<<endl;
    }
    return 0;
}