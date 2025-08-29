#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
vector<int> adj[N];
vector<int> component(N,-1);
int n,m,u,v, cur_id;
void input(){
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int u){
    cout<<u<<" ";
    component[u]=v;
    for(int i=1;i<=n;i++){
        if(component[v]==-1) {dfs(v);}
    }
}
int main(){
   // freopen("hieu.inp","r", stdin);
    //freopen("h.out","w", stdout);
    input();
    for(int i=1)
}