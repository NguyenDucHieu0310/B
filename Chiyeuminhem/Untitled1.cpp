#include<iostream>;
#include<vector>;
#include<math.h>;
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        for(int i=1;i<height.size();i++){
            bool check =1;
            for(int j=height.size();j>=i+1;j--){
                if((j-i)*min(height[i], height[j])>max)
                max=(j-i)*min(height[i], height[j]);
                for(int k= j-1;k>i;k--){
                    if(height[k]>height[j]) {check =0; break;}
                }
                if(check) break;
            }
        }
        return max;
    }
};
int main(){
	Solution solution;
	int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::vector<int> h(arr, arr + n);
	int t=solution.maxArea(h);
	cout<<t;
}
