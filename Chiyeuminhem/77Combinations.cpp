class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        combinations(result, combination, n, k, 1)  ;
        return result;
    }
    void combinations(vector<vector<int>>&result, vector<int>&combination, int n, int k, int cur){
        if(combination.size()==k) result.push_back(combination);
        else{
            for(int i=cur;i<=n;i++){
                combination.push_back(i);
                combinations(result, combination,n, k, i+1);
                combination.pop_back();
            }
        }
        
    }
};