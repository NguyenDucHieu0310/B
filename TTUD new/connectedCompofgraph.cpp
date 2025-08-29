#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&graph, vector<bool>&visited){
    visited[node]=true;
    for(int adjacent : graph[node])
        if(!visited[adjacent])       dfs(adjacent,graph,visited);
}
int Component(int N, vector<vector<int>>&edges){
    vector<vector<int>> graph(N+1);
    vector<bool> visited(N+1,false);
    for(vector<int> x:edges){
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }
    int count=0;
    for(int node=1;node<=N;node++){
        if(!visited[node]){
            dfs(node,graph,visited);
            count++;
        }
    }
    return count;
}
int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(M, vector<int>(2));
    for (int i = 0; i < M; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int result = Component(N,edges);
    cout << result << endl;

    return 0;
}