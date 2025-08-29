#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n, m, cur_num=0;
vector<int> adj[N];
vector<int> low(N), num(N,-1);
vector<bool> connect(N, false);
stack<int> s;
void scc(int u){
    s.push(u);
    connect[u]=true;
    low[u]=num[u]=++cur_num;
    for(auto v : adj[u]){
        if(num[v]==-1){
            scc(v);
            low[u]=min(low[u], low[v]);
        }
        else {if(connect[v]) low[u]=min(low[u], num[v]);}
    }
    if(low[u]==num[u]){
        cout<<"TPLT: ";
        while(1){
            int v=s.top();
            cout<<v<<" ";
            connect[v]=false;
            if(v==u) break;

        }
        cout<<endl;
    }
}
void input(){
    cin>>n>>m;
    int u, v;
    for(int i=0; i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
}
int main(){
    input();
    for(int i=0; i<n;i++){
        if(num[i]==-1) scc(i);
    }
}