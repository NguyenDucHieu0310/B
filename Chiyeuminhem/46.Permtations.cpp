class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allpermute;
        vector<int> currentPermute;
        backtrack(nums, currentPermute, allpermute);
        return allpermute;

    }
    void backtrack(vector<int>& nums, vector<int>& currentPermute,vector<vector<int>>&allpermute  ){
        if(nums.empty()){
            allpermute.push_back(currentPermute);
            return;
        }
        for(int i=0; i<nums.size();i++){
            int num=nums[i];
            currentPermute.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            backtrack(nums, currentPermute, allpermute);
            nums.insert(nums.begin()+i, num);
            currentPermute.pop_back();
        }
    }
};
