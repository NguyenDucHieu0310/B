#include<bits/stdc++.h>
using namespace std;
int m;
int Hash(string s){
    int n=s.length();
    int res=0;
    for(int i=0;i<n;i++){
        res=res*256+int(s[i]);
        
        res%=m;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        cout<<Hash(s)<<endl;
    }
}