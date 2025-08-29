class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
       
        for(int size=0; size<=n;size++){
             vector<int> current;
            backtrack(result, current, nums, 0, size, n);
        }  
        return result;      
    }
    void backtrack(vector<vector<int>>&result, vector<int>&current, vector<int>&nums, int start, int size, int n){
        if(current.size()==size) result.push_back(current);
        else{
            for(int i=start; i<n; i++){
                current.push_back(nums[i]);
                backtrack(result, current, nums, i+1, size, n);
                current.pop_back();
            }
        }
    }
};