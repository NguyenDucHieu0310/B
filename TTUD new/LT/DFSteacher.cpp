#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
vector<int> adj[N];
vector<bool> visited(N, false);
int n,m,u,v;
void input(){
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
    }
}
void dfs(int u){
    cout<<u<<" ";
    visited[u]=true;
    for(auto v:adj[u]){
        if(!visited[v]) dfs(v);
    }
}
int main(){
   // freopen("hieu.inp","r", stdin);
    //freopen("h.out","w", stdout);
    input();
    dfs(1);
}