#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1);
        int count=9;
        dp[0]=1;  dp[1]=10;
        if(n<2) return dp[n];
        for(int i=2; i<=n;i++){
            count*=(11-i);
            dp[i]=dp[i-1]+count;
        }
        return dp[n];
    }
};

int main() {
    int n ; cin>>n;
    Solution sol;

    cout << sol.countNumbersWithUniqueDigits(n) << endl;
    return 0; // Return 0 to indicate successful program execution
}
