#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canCross(vector<int>& nums) {
        int n=nums.size();
        int prev=1;
        for(int i =1; i<nums.size();i++ ){
            int cur=nums[i]-nums[i-1];
            if(abs(cur-prev)>1) return false;
            prev=cur;
        }
        return true;
    }
};
int main(){
    vector<int> nums={0,1,3,5,6,8,12,17};
    Solution sol;
    int b=sol.canCross(nums);
}