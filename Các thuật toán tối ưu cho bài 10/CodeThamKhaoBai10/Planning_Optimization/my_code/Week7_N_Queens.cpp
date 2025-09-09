#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> random_board(int n){
    vector<int> board(n);
    for (int i = 0; i < n; ++i) {
        board[i] = rand() % n + 1;
    }
    return board;
}

//print the board
void print_board(const vector<int>& board) {
    for (int i = 0; i < n; ++i) {
        cout << board[i] << " ";
    }
}

// cal the total conflict of the board
int calculate_cost(const vector<int>& board) {
    int cost = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (board[i] == board[j] || abs(board[i] - board[j]) == abs(i - j)) {
                cost++;
            }
        }
    }
    return cost;
}

//find the most violation queen
int get_queen(const vector<int>& board){
    int queen_id;   //solution
    int conflict[n];
    int max_conflict = 0;
    for(int i =0; i<n; i++){
        conflict[i] = 0;
        for (int j=0; j<n; j++){
            if(j==i){
                continue;
            }
            if (board[i] == board[j] || abs(board[i] - board[j]) == abs(i - j)) {
                conflict[i];
            }
        }
        if(max_conflict < conflict[i]){
            max_conflict = conflict[i];
            queen_id = i;
        }
    }
    return queen_id;
}

vector<vector<int>> get_neighbors(const vector<int>& board, int queen_id){
    vector<vector<int>> neighbors;
    for(int i=0; i<n; i++){
        if (i == queen_id){
            continue;
        }
        vector<int> current_board;
        for(int j=0; j<n; j++){
            if(j != queen_id){
                
            }
        }
    }
}
