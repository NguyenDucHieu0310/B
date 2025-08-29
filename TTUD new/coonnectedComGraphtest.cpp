#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&graph, vector<bool>&visited){
    visited[node]=true;
    for(int adjacent : graph[node])
        if(!visited[adjacent])       dfs(adjacent,graph,visited);
}
int main(){
    int N=8, M=8;
    
    vector<vector<int>> edges={{1,2},{1,7},{1,8},{2,7},{4,5},{4,6},{5,6},{7,8}};
    
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
    cout << count << endl;
    return 0;
}