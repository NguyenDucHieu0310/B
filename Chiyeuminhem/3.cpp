#include <bits/stdc++.h>
using namespace std;

// Structure to represent a customer
struct Customer {
    int position;
    int demand;
};

// Function to solve the delivery scheduling problem
int solveDeliveryScheduling(vector<Customer>& customers, vector<vector<int>>& distance, int K, int Q) {
    int n = customers.size();
    vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX));

    // Base case: no customers
    for (int k = 0; k <= K; ++k) {
        dp[0][k] = 0;
    }

    // Dynamic programming
    for (int i = 1; i < n; ++i) {
        for (int k = 1; k <= K; ++k) {
            for (int j = 0; j < i; ++j) {
                if (dp[j][k - 1] != INT_MAX) {
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + distance[customers[j].position][customers[i].position]);
                }
            }
        }
    }

    // Find the minimum distance for K trucks
    int minDistance = INT_MAX;
    for (int k = 1; k <= K; ++k) {
        minDistance = min(minDistance, dp[n - 1][k]);
    }

    // Check if the solution is feasible
    if (minDistance == INT_MAX || minDistance > Q) {
        return -1; // No feasible solution
    }

    return minDistance;
}

int main() {
    int n, K, Q;
    cin >> n >> K >> Q;

    vector<Customer> customers(n);
    for (int i = 0; i < n; ++i) {
        cin >> customers[i].demand;
    }

    vector<vector<int>> distance(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distance[i][j];
        }
    }

    // Call the function to solve the problem
    int result = solveDeliveryScheduling(customers, distance, K, Q);

    cout << result << endl;

    return 0;
}
