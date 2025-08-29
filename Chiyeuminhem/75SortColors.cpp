#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int curr = 0;
        while(curr<=end){
            if(nums[curr]==0){
                swap(nums[curr], nums[start]);
                start++; curr++;
            }
            else if(nums[curr]==2){
                swap(nums[curr], nums[end]);
                end--; 
            }
            else curr++;
        }        
    }
};


int main() {
    int n;
    std::cout << "Enter the size of the vector: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    Solution solution;

    solution.sortColors(nums);

    std::cout << "Sorted vector: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
   
    std::cout << std::endl;

    return 0;
}
