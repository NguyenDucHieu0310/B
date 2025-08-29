#include<bits/stdc++.h>
using namespace std;
const int N=1000;
const int INF=INT_MAX;
int n,m ;
typedef pair<int,int> ii;
int C[N], D[N];
vector<int> dist(N, INF), edge_dist(N, 0);
vector<int> visited(N,false);
vector<int> adj[N];
int w[N][N];
void BFS(int s){//s=start
    visited.resize(N, false);
    queue<int> Q;
    edge_dist[s]=0;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        visited[u]=true;
        w[s][u]=C[s];
        for(int v : adj[u]){
            if(!visited[v]){
                edge_dist[v]=edge_dist[u]+1;
                if(edge_dist[v]<=D[s]){
                    Q.push(v);
                }
            }
        }
    }

}
void builGraph(){
    for(int i=1; i<=n; i++){
        for(int j=1;j<=n; j++){
            w[i][j]=i==j?0:INF;
        }

    }
    for(int i=1; i<=n; i++) BFS(i);
    for(int i=1; i<=n; i++){
        for(int j=1;j<=n; j++){
            cout << w[i][j] << " ";
        }
        cout << endl;

    }
}
void input(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>C[i]>>D[i];
    int u, v;
    for(int i=0; i<m ;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void Dijkstra(int s, int t){
    priority_queue<ii, vector<ii>,greater<ii>> pq;
    dist[s]=0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(u==t) return;
        for(int v=1; v<=n; v++){
            if(w[u][v]<INF){
                if(dist[v]>dist[u]+w[u][v]){
                    dist[v]= dist[u]+w[u][v];
                    pq.push(make_pair(dist[v], v));
                    cout<<v<<" "<<dist[v]<<endl;
                }
                
            }
        }
    }
}
int main(){
    freopen("data.inp", "r", stdin);
    input();
    builGraph();
    Dijkstra(1,n);
    
    cout<<dist[n];
    
}