#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n, m;
vector<int> adj[N];
vector<int> low(N),num(N,-1);
vector<pair<int, int>> res;
int cur_num=0;

void dfs(int u, int p){
    low[u]=num[u]=++cur_num;
    for(auto &v: adj[u]){
        if(v==p) continue;
        if(num[v]==-1){
            dfs(v,u);
            low[u]=min(low[u], low[v]);
        }
        else low[u]=min(low[u], num[v]);
        if(low[v]>num[u]) res.push_back(make_pair(u,v));
        
    }

}
void input(){
    cin>>n>>m;
    int u, v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
int main(){
    input();
    for(int u=1; u<=n;u++){
        if(num[u]==-1) dfs(u,-1);
    }
    for(auto e: res) cout<<e.first<<" "<<e.second<<endl;
}