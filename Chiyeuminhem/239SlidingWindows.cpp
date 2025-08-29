/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
3   3  -1  -3  5  3  6  7
3   3   

 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();//n=8
        for(int i=k-1;i>=1;i--){
            nums[i-1]=max(nums[i],nums[i-1]);

        }
        //for(auto x:nums) cout<<x<<" ";
        cout<<endl;
        for(int i=k-1;i<n;i++){
            for(int j=i-k+1;j<=i;j++){
                if(nums[j]<nums[i]) nums[j]=nums[i];
                
            }
        }
        vector<int>res(nums.begin(),nums.begin()+n-k+1);
        return res;
    }
};
int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    Solution sol;
    vector<int> res=sol.maxSlidingWindow(nums,3);
    for(auto x:res) cout<<x<<" ";
}