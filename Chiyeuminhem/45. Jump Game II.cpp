#include<vector>
#include<iostream>    
using namespace std;
    int jumpMax(vector<int>&nums,int  i){
        if(i+nums[i]>=nums.size()-1) return 1;
        int maxjump=0,i2=0;
        for(int j=1; j<=nums[i]; j++ ){
            if(j+nums[i+j]>maxjump){
                i2=i+j;
                maxjump=j+nums[i+j];
            }
        }
        return jumpMax(nums,i2)+1;
    }
    int jump(vector<int>& nums) {
       if(nums.size()==1) return 0;
       return jumpMax(nums,0);

    }

int main(){
    /*int n;
    std::cout << "Enter the size of the vector: ";
    std::cin >> n;

    std::vector<int> heights;
    std::cout << "Enter " << n << " heights: ";

    for (int i = 0; i < n; i++) {
        int height;
        std::cin >> height;
        heights.push_back(height);
    }*/
    vector<int> heights={1,3,2,1,1,4,3,5};
    cout<<jump(heights);
}

