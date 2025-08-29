#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++){
            result^=nums[i];
        }
        return result;
    }
};
int main(){
    vector <int> nums={1,2,1};
    Solution solution;
    cout<<solution.singleNumber(nums);


}
