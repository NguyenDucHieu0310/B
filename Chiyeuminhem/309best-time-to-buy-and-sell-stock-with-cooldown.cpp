#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        if(n<=1) return profit;
        int p=0;
        while(p<n-1){
            if(prices[p]<prices[p+1]){
                profit+=prices[p+1]-prices[p];
            }
            p++;            
        }
        return profit;
    }
};
int main(){
    Solution sol;
    vector<int>prices={1,2,3,0,2};
    int res=sol.maxProfit(prices);
    cout<<res;
}
