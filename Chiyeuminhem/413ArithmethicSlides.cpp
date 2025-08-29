#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        for(int i=1; i<nums.size(); i++){
            nums[i-1]-=nums[i];
        }
        int count=0, id=0;
        while(id<n-1){
            int cur_size=1;
            while(id<n-1&&nums[id]==nums[id+1]){
                cur_size++;
                id++;
            }
            count+=cur_size*(cur_size-1)/2;
            id++;
        }
        return count;
    }
};
int main(){
    vector<int> nums={1,2,3,4,5,8};
    Solution sol;
    cout<<sol.numberOfArithmeticSlices(nums);
}