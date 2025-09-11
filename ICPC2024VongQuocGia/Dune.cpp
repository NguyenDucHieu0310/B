#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--){
        long long m, n, p, a;
        cin>>m>>n>>p>>a;
        a=a%(m+n+p);
        if(a<m) cout<<"Guiding Beat";
        else if(a<m+n) cout<<"Warning Beat";
        else cout<<"Resting Phase";
        cout<<endl;


    }
    
    return 0;
}