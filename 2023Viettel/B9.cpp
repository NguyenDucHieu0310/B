#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e15;

struct HopcroftKarp {
    int nL, nR;
    vector<vector<int>> adj;
    vector<int> dist, pairU, pairV;
    HopcroftKarp(int _nL=0, int _nR=0){ init(_nL,_nR); }
    void init(int _nL, int _nR){
        nL = _nL; nR = _nR;
        adj.assign(nL+1, {});
        pairU.assign(nL+1, 0);
        pairV.assign(nR+1, 0);
        dist.assign(nL+1, 0);
    }
    void addEdge(int u, int v){ // 1-based, v in [1..nR]
        if(u<1||u>nL||v<1||v>nR) return;
        adj[u].push_back(v);
    }
    bool bfs(){
        queue<int> q;
        for(int u=1;u<=nL;++u){
            if(pairU[u]==0){
                dist[u]=0;
                q.push(u);
            } else dist[u]=INT_MAX;
        }
        bool reachable=false;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: adj[u]){
                int pu = pairV[v];
                if(pu==0) reachable = true;
                else if(dist[pu]==INT_MAX){
                    dist[pu]=dist[u]+1;
                    q.push(pu);
                }
            }
        }
        return reachable;
    }
    bool dfs(int u){
        for(int v: adj[u]){
            int pu = pairV[v];
            if(pu==0 || (dist[pu]==dist[u]+1 && dfs(pu))){
                pairU[u]=v;
                pairV[v]=u;
                return true;
            }
        }
        dist[u]=INT_MAX;
        return false;
    }
    int maxMatching(){
        fill(pairU.begin(), pairU.end(), 0);
        fill(pairV.begin(), pairV.end(), 0);
        int result=0;
        while(bfs()){
            for(int u=1;u<=nL;++u){
                if(pairU[u]==0 && dfs(u)) ++result;
            }
        }
        return result;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    if(!(cin>>n>>m>>k)) return 0;
    const int MAXN = 305;
    static ll dist[MAXN][MAXN];
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dist[i][j] = (i==j?0:INF);
    for(int i=0;i<m;++i){
        int u,v; ll w;
        cin>>u>>v>>w;
        if(w < dist[u][v]){
            dist[u][v]=w;
            dist[v][u]=w;
        }
    }
    // Floyd-Warshall
    for(int t=1;t<=n;++t)
        for(int i=1;i<=n;++i) if(dist[i][t]<INF)
            for(int j=1;j<=n;++j)
                if(dist[t][j]<INF && dist[i][j] > dist[i][t] + dist[t][j])
                    dist[i][j] = dist[i][t] + dist[t][j];

    vector<int> p(k+1), qv(k+1);
    for(int i=1;i<=k;++i) cin>>p[i];
    for(int i=1;i<=k;++i) cin>>qv[i];

    // cost matrix: employee i (qv[i]) to customer j (p[j])
    vector<vector<ll>> cost(k+1, vector<ll>(k+1, INF));
    ll hi = 0;
    for(int i=1;i<=k;++i){
        for(int j=1;j<=k;++j){
            cost[i][j] = dist[qv[i]][p[j]];
            if(cost[i][j] < INF) hi = max(hi, cost[i][j]);
        }
    }
    ll lo = -1;
    // binary search minimal maximum distance
    while(lo+1<hi){
        ll mid = lo + (hi-lo)/2;
        HopcroftKarp hk(k,k);
        for(int i=1;i<=k;++i){
            for(int j=1;j<=k;++j){
                if(cost[i][j] <= mid) hk.addEdge(i,j);
            }
        }
        int mat = hk.maxMatching();
        if(mat==k) hi = mid;
        else lo = mid;
    }
    // build final matching at hi
    HopcroftKarp hk(k,k);
    for(int i=1;i<=k;++i)
        for(int j=1;j<=k;++j)
            if(cost[i][j] <= hi) hk.addEdge(i,j);
    int mat = hk.maxMatching();
    // hk.pairU[u] = v assigned
    vector<int> ans(k+1, 1);
    for(int i=1;i<=k;++i){
        if(hk.pairU[i]>0) ans[i]=hk.pairU[i];
        else ans[i]=1; // fallback (shouldn't happen)
    }
    cout<<hi<<"\n";
    for(int i=1;i<=k;++i){
        if(i>1) cout<<' ';
        cout<<ans[i];
    }
    cout<<"\n";
    return 0;
}