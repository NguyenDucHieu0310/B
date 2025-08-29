#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int a[MAXN];
int M[30][MAXN];
int m,n;

void precompute(){
    for(int j=0;j<30;j++)
        for(int i=0;i<n;i++)
            M[j][i]=-1;
    for(int i=0;i<n;i++)
        M[0][i]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<=n;i++)
            M[j][i]=min(M[j-1][i],M[j-1][i+(1<<(j-1))]);
}
int rmg(int i, int j){
    int l=log2(j-i+1);
    
    return min(M[l][i],M[l][j-(1<<l)+1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int sum=0;
   
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    precompute();
    cin>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        cout<<rmg(a,b)<<endl;
        sum+=rmg(a,b);
    }
    cout<<sum;
}