#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;
int a[MAXN][MAXN];
int n,m,r,c;
queue<pair<int,int>> q;
bool visited[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int solve(){
    q.push(make_pair(r,c));
    visited[r][c]=true;
    dist[r][c]=0;
    while(!q.empty()){
        pair<int,int> u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int vx=u.first+dx[i];
            int vy=u.second+dy[i];
            if(vx<1||vx>n||vy<1||vy>m) return dist[u.first][u.second]+1;
            if(!a[vx][vy]&&!visited[vx][vy]){
                q.push(make_pair(vx,vy));
                visited[vx][vy]=true;
                dist[vx][vy]=dist[u.first][u.second]+1;
            }


        }
    }
    return -1;
}
void input(){
    cin>>n>>m>>r>>c;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       cin>>a[i][j];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    cout<<solve();
}