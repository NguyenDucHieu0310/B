class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> currentPermutation;
        vector<bool> used(nums.size(), false); // M?ng ghi nh?n c�c s? d� du?c s? d?ng
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
                continue; // B? qua s? d� du?c s? d?ng
            }
            // Ki?m tra tr?ng th�i c?a s? tru?c d� d? d?m b?o kh�ng t?o ra c�c ho�n v? tr�ng l?p
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

