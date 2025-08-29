class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int first=0, last=m*n-1;

        while(first<=last){
            int mid=(first+last)/2;
            int col=mid%n;
            int row=mid/n;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) first=mid+1;
            else last=mid-1;
        }       
        return false;         
    }
};
