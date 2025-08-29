#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, x,y;
    cin>>n>>m;

    vector<int> dur(n+1);
    for(int i=1; i<=n; i++) cin>>dur[i];

    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1);
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        deg[y]++;
    }

    vector<int> Times(n+1,0);
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(deg[i]==0){
            Times[i]=dur[i];
            q.push(i);
        }
    }
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        for(int next : adj[fr]){
            if(--deg[next]==0){
                q.push(next);
                
            }  
            Times[next]=max(Times[next], dur[next]+Times[fr]);          
        }        
    }
    int res=*max_element(Times.begin(), Times.end());
    cout<<res<<endl;
}