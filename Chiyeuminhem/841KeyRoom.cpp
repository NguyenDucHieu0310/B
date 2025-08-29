#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool canVisitAllRooms(vector<vector<int>>& s) {
        int n=s.size(), count=1;
        vector<int> visited(n,0);
        queue<int>q;
        visited[0]=1;
        for(int x: s[0]){
            q.push(x);
            visited[x]=1;
            count++;            
        }
        while(!q.empty()){
            int x=q.front();
            
            q.pop();
            for(auto nb: s[x]){
                if(visited[nb]==0){
                    q.push(nb);
                    count++;
                    //cout<<nb<<" "<<n<<endl;
                    visited[x]=1;
                    if(count==n) return true;
                }
            }
        }
        return false;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1,3}, {3,0,1}, {2},{0}};
    bool result = solution.canVisitAllRooms(intervals);

    cout << "Minimum arrows needed: " << result << endl;

    return 0;
}