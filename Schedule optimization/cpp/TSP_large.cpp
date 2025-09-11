#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<vector<int>> c;
vector<vector<int>> dp;
vector<vector<int>> nextNode;
vector<int> path;  // Lưu lại đường đi cho heuristic

int tsp_dp(int pos, int mask) {
    if (mask == (1 << n) - 1) {
        return c[pos][0];
    }
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int new_cost = c[pos][i] + tsp_dp(i, mask | (1 << i));
            if (new_cost < ans) {
                ans = new_cost;
                nextNode[pos][mask] = i;
            }
        }
    }
    return dp[pos][mask] = ans;
}

void print_path() {
    int mask = 1;
    int pos = 0;
    cout << pos + 1;
    while (mask != (1 << n) - 1) {
        pos = nextNode[pos][mask];
        cout << " " << pos + 1;
        mask |= (1 << pos);
    }
}

int nearest_neighbor(int current = 0) {
    vector<bool> visited(n, false);
    int total_cost = 0;
    
    path.clear(); // Xóa đường đi cũ
    path.push_back(0);  // Bắt đầu từ đỉnh 0
    visited[0] = true;
    
    for (int i = 1; i < n; i++) {
        int next = -1;
        int min_cost = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && c[current][j] < min_cost) {
                min_cost = c[current][j];
                next = j;
            }
        }
        visited[next] = true;
        total_cost += min_cost;
        current = next;
        path.push_back(next);  // Lưu đỉnh tiếp theo vào đường đi
    }
    total_cost += c[current][0];  // Quay về đỉnh 0
    return total_cost;
}

void print_heuristic_path(vector<int> path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1 << " ";
    }
    // cout << endl;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    c.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    cout << n << endl;
    if (n <= 20) {
        dp.resize(n, vector<int>(1 << n, -1));
        nextNode.resize(n, vector<int>(1 << n, -1));

        int optimal_cost = tsp_dp(0, 1);
        // cout << "Optimal solution: " << optimal_cost << endl;
        print_path();
    } else {
        // int heuristic_cost = nearest_neighbor(0);
        // cout << "Heuristic solution: " << heuristic_cost << endl;

        // run heuristic algorithm with some starting point and choose the best one
        vector<int> best_path;
        int best_cost = INT_MAX;
        int num_iter = min(100, n);
        for (int i = 0; i < num_iter; i++) {
            int heuristic_cost = nearest_neighbor(i);
            if (heuristic_cost < best_cost) {
                best_cost = heuristic_cost;
                // copy path to best_path
                best_path.clear();
                for (int j = 0; j < path.size(); j++) {
                    best_path.push_back(path[j]);
                }
            }
        }
        cout << "Heuristic solution: " << best_cost << endl;
        print_heuristic_path(best_path);  // In ra đường đi tìm được từ heuristic
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}