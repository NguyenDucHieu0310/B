class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp=triangle.back();
        int rows=triangle.size();
        for(int i=rows-2;i>=0;i--)
        for(int j=0;j<=i;j++)
        dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
        return dp[0];
    }
};