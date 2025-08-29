class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result;
        for(int i=0; i<n;i++){
            vector<int> curRows;
            curRows.push_back(1);
            for(int j=0;j<=i-2;j++){
                curRows.push_back(result[i-1][j]+result[i-1][j+1]);
            }
            if(i>0) curRows.push_back(1);
            result.push_back(curRows);
        }
        return result;
    }
};