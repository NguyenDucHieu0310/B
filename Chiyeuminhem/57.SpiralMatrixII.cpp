class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        int num=1, topRow=0, bottomRow=n-1, leftCol=0, rightCol=n-1;
        while(num<=n*n){
            for(int i=leftCol;i<=rightCol;i++) result[topRow][i]=num++;
            topRow++;
            for(int i=topRow;i<=bottomRow;i++) result[i][rightCol]=num++;
            rightCol--;
            for(int i=rightCol;i>=leftCol;i--) result[bottomRow][i]=num++;
            bottomRow--;
            for(int i=bottomRow;i>=topRow;i--) result[i][leftCol]=num++;
            leftCol++;
        }
        return result;
    }
};