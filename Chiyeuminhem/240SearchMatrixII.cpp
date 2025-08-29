#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0) return false;
        return Helper(matrix,0,m-1,target);
    }

    bool Helper(vector<vector<int>>& matrix, int r1, int r2, int target){
        int m=matrix.size();
        int n=matrix[0].size();
        int rowmid=(r1+r2)/2;
        if(matrix[rowmid][n-1]==target||(rowmid<m-1&&matrix[rowmid+1][0]==target)) return true;

        if(r1==r2){
            for(int i=0;i<n;i++)
            if(matrix[r1][i]==target) return true;
            return false;
        }
        
        bool firstPart=matrix[rowmid][n-1]>target?Helper(matrix,r1,rowmid,target):false;
        if (firstPart) return true;

        bool SecondPart=matrix[rowmid+1][0]<target?Helper(matrix,rowmid+1,r2,target):false;

        return SecondPart;     
    }
};
int main(){
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution sol;
    bool res=sol.searchMatrix(matrix,28);
    cout<<res;

}