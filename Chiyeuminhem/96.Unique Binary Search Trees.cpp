#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   int mem[22];

    Solution() {
        mem[0]=1;
        mem[1]=1;
        for (int i = 2; i < 22; i++) {
            mem[i] = -1;
        }
    }

    int numTrees(int n) {
        
        if(mem[n]!=-1) return mem[n];
        int temp=0;
        for(int i=0;i<n;i++) temp+=numTrees(i)*numTrees(n-1-i);
        mem[n]=temp;
        return temp;
    }
};
int main(){
	Solution solution;
   
    
    int result = solution.numTrees(4);
    std::cout << "Number of unique BSTs with "  << " nodes: " << result << std::endl;
    return 0;
}
