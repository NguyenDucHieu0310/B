#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<int> queenPositions(n,-1);
        backtrack(solutions, queenPositions, 0,n);
        return solutions  ;      
    }
    void backtrack(vector<vector<string>>& solutions, vector<int>& queenPositions, int row, int n){
        if(row==n){ solutions.push_back(createBoard(queenPositions, n)); return;}
        for(int col=0;col<n;col++){
            if(isValidPosition(queenPositions, row, col)){
            queenPositions[row]=col;
            backtrack(solutions, queenPositions, row+1, n);
            queenPositions[row]=-1;
        }
    }
    }
    bool isValidPosition(vector<int>& queenPositions, int row, int col){
        for(int i=0; i<row; i++){
            if(queenPositions[i]==col||abs(queenPositions[i]-col)==abs(i-row)) return false;
        }
        return true;
    }
    vector<string> createBoard(vector<int> &queenPositions, int n){
        vector<string> board(n, string(n,'.'));
        for(int row=0; row<n;row++){
            int col=queenPositions[row];
            board[row][col]='Q';
        }
        return board;
    }
};

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    Solution solution;
    vector<vector<string>> solutions = solution.solveNQueens(n);

    // Print the solutions
    for (const auto& board : solutions) {
        for (const auto& row : board) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}

