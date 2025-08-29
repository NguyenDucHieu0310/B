#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        
        int res=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1) res++;
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1) res++;
        }
        
        for(int i=1; i<m;i++){
            for(int j=1; j<n; j++){
                if(grid[i][j]==1){
                    res+=(2-grid[i-1][j]-grid[i][j-1]);

                }
            }
        }
        return 2*res;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> g={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    int res=sol.islandPerimeter(g);
    cout<<res;
}