#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> res;
        vector<vector<int>> graph(n,vector<int>());
        vector<int> Degree(n,0);
        for(auto edge:pre){
            graph[edge[1]].push_back(edge[0]);
            Degree[edge[0]]++;
        }
        while(res.size()<=n){
            bool countChange=false;
            for(int i=0;i<n;i++){
                if(Degree[i]==0){
                    countChange=true;
                    res.push_back(i);
                    for(auto x:graph[i]) Degree[x]--;
                    Degree[i]=1;
                }
            }
            if (countChange==false) break;
        }  
        return res.size()==n? res:vector<int>();
    }         
};
int main(){
    int numCourse=4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0},{3,1},{3,2}};
    Solution sol;
    vector<int> result=sol.findOrder(numCourse,prerequisites2);
    for(auto x:result) cout<<x;

}