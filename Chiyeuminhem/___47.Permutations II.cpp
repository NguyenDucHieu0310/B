class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> currentPermutation;
        vector<bool> used(nums.size(), false); // M?ng ghi nh?n các s? dã du?c s? d?ng
        backtrack(nums, currentPermutation, used, permutations);
        return permutations;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& currentPermutation, vector<bool>& used, vector<vector<int>>& permutations) {
        if (currentPermutation.size() == nums.size()) {
            permutations.push_back(currentPermutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue; // B? qua s? dã du?c s? d?ng
            }
            // Ki?m tra tr?ng thái c?a s? tru?c dó d? d?m b?o không t?o ra các hoán v? trùng l?p
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            currentPermutation.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, currentPermutation, used, permutations);
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
};

