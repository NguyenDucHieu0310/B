#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n,vector<int>());
        vector<int> inDegree(n,0);
        //graph[i] là tập các task cần i complete
        for(auto edge:pre){
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]+=1;            
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curCourse=q.front();
            q.pop();
            for(int nb:graph[curCourse]){
                inDegree[nb]--;
                if(inDegree[nb]==0) q.push(nb);
            }
        }
        return all_of(inDegree.begin(), inDegree.end(), [](int deg) { return deg == 0; });
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>> pre={{0,1},{0,1}};
    Solution Sol;
    cout<<Sol.canFinish(n,pre);
}