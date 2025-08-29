#include<bits/stdc++.h>
using namespace std;
int n=7, m;
const int INF=1e9;

struct edge{
    int u, v, w;
    edge(int _u, int _v, int _w):
    u(_u), v(_v), w(_w){}
};
vector<vector<edge>> edges(n + 1);
vector<edge> Prim(int start, const vector<vector<edge>>&adj){
    int n=adj.size()-1;
    vector<edge> res;
    vector<bool> inTree(n+1, false);
    vector<int> dist(n+1, INF);
    vector<int> near(n+1,-1);
    dist[start]=0; near[start]=start; 
    while(res.size()<n-1){
        int u=-1, v=-1, w=INF;
        for(int x=1; x<=n; x++){
            if(!inTree[x]&&dist[x]<w){
                v=x;
                w=dist[x];
                u=near[x];
            }
        }
        if(v==-1) return res;
        inTree[v]=true;
        if(v!=start) res.push_back(edge(u,v,w));
        for(const edge&e:adj[v]){
            int t=e.v, w=e.w;
            if(dist[t]>w){
                dist[t]=w;
                near[t]=v;
            }
        }
    }
    return res;
}
void input(){
    cin>>n>>m;
    int u, v,w;
    while(m--){
        cin>>u>>v>>w;
        edges[u].push_back(edge(u,v,w));
        edges[v].push_back(edge(v,u,w));
    }
}
int main(){
    freopen("data.inp", "r", stdin);
    freopen("output.inp","w", stdout);
    input();
    vector<edge> res=Prim(1, edges);
    for(auto x: res){
        cout<<x.u<<x.v<<x.w<<endl;
    }

}