#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int n, a[MAXN], pos=-1;
int mem[MAXN];
int dp(int i){
    if(mem[i]!=-1) return mem[i];
    int res=1;
    for(int j=1; j<i; j++){
        if(a[i]>a[j]) res=max(res, 1+dp(j));
    }
    return mem[i]=res;
}
int solve(){
    int ans=1;
    for(int i=1; i<=n; i++){
        if(ans<dp(i)){
            ans=dp(i);
            pos=i;
        }
    }
    return ans;
}
void trace(int i){
    for(int j=1;j<i; j++){
        if(a[j]<a[i]&& mem[i]==1+mem[j]){
            trace(j);
            break;
        }
    }
    cout<<a[i]<<" ";
}

int main(){
    memset(mem,-1,sizeof(mem));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<solve();
    trace(pos);
    
}