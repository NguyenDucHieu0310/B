#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> random_board(int n) {
    vector<int> board(n);
    for (int i = 0; i < n; ++i) {
        board[i] = rand() % n + 1;
    }
    return board;
}

void print_board(const vector<int>& board) {
    for (int i = 0; i < n; ++i) {
        cout << board[i] << " ";
    }
}

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

int get_queen(const vector<int>& board) {
    int queen_id;
    int conflict[n];
    int max_conflict = 0;
    for (int i = 0; i < n; i++) {
        conflict[i] = 0;
        for (int j = 0; j <= i; j++) {
            if (j != i) {
                if ((board[i] == board[j] || abs(board[i] - board[j]) == abs(i - j))) {
                    conflict[i] ++;
                }
            }
        }
        if (conflict[i] > max_conflict) {
            max_conflict = conflict[i];
            queen_id = i;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     if(board[i] == max_conflict) queen_id.push_back(i);
    // }
    return queen_id;
}

vector<vector<int>> get_neighbors(const vector<int>& board, int queen_id) {
    vector<vector<int>> neighbors;
    vector<vector<int>> chosen_neighbors;
    int cost, min_cost = 1e9;
    
    for (int i = 0; i < n; ++i) {
        if (i != board[queen_id]) { // Nếu không trùng với vị trí hiện tại của quân hậu
            vector<int> neighbor = board;
            neighbor[queen_id] = i; // Di chuyển quân hậu hàng i sang cột j
            min_cost = min(calculate_cost(neighbor), min_cost); // Tính chi phí bảng
            neighbors.push_back(neighbor);
        }
    }

    for (auto neighbor: neighbors) {
        if (calculate_cost(neighbor) > min_cost) chosen_neighbors.push_back(neighbor); 
    }
    return chosen_neighbors;
}

vector<int> hill_climbing(vector<int> board) {
    int current_cost = calculate_cost(board);

    while (true) {
        int queen_id = get_queen(board);
        vector<vector<int>> neighbors = get_neighbors(board, queen_id);
        vector<int> next_board;
        int next_cost = current_cost;

        // Tìm trạng thái lân cận có chi phí thấp nhất
        for (const auto& neighbor : neighbors) {
            int cost = calculate_cost(neighbor);
            next_board = neighbor;
            next_cost = cost;
            board = next_board;
            current_cost = next_cost;
            int next_queen_id = get_queen(next_board);
            vector<vector<int>> next_neighbors = get_neighbors(next_board, next_queen_id);
            for (const auto& next_neighbor : next_neighbors) {
                if (calculate_cost(next_neighbor) < current_cost) continue;
            }
        }

        // Nếu cost = 0, dừng lại
        if (next_cost == 0) break;
    }

    return board;
}

int main() {
    cin >> n;
    srand(time(0));
    vector<int> initial_board = random_board(n);

    print_board(initial_board); cout << endl;

    vector<int> final_board = hill_climbing(initial_board);

    cout << calculate_cost(final_board); cout << endl;

    print_board(final_board);
    return 0;
}