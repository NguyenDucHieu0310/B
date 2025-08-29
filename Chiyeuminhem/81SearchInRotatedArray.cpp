class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int n=nums.size(), rotate;
        for(int i=0; i<n-1;i++){
            if(nums[i]>nums[i+1]){
                rotate=i;
                break;
            }
        }
        if(target==nums[rotate]) return true;
        if(target>=nums[0]){
            int start=0, end=rotate-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(target==nums[mid]) return true;
                if(target>nums[mid]){
                    start=mid+1;
                }
                else end=mid-1;
            }
        }
        else if(target<=nums[n-1]){
            int start=rotate+1;
            int end=n-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(target==nums[mid]) return true;
                if(target>nums[mid]){
                    start=mid+1;
                }
                else end=mid-1;
            }

        }
        return false;           
    }
    
};