#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int pro = 1;
        int i = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            while (pro < k && i >= 0) {
                pro *= nums[i];
                if (pro < k) {
                    i--;
                }
            }
            res += j - i+1; // Cập nhật kết quả
            if (i != j) { // Tránh trường hợp i == j thì không chia
                pro /= nums[j]; // Cập nhật pro
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {10, 2, 5, 6};
    Solution sol;
    int n = sol.numSubarrayProductLessThanK(nums, 100);
    cout << n;
    return 0;
}
