#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCount = INT_MAX;

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), [](int a, int b) { return a > b; });
        return countCoins(coins, amount, 0, 0);
    }

    int countCoins(vector<int>& coins, int amount, int id, int count) {
        if (amount == 0) return count;
        if (id == coins.size() || amount < coins.back()) return -1;

        for (int t = amount / coins[id]; t >= 0; t--) {
            int temp = countCoins(coins, amount - t * coins[id], id + 1, count + t);
            if (temp != -1) minCount = min(minCount, temp);
        }

        return (minCount == INT_MAX) ? -1 : minCount;
    }
};

int main() {
    vector<int> coins = {411,412,413,414,415,416,417,418,419,420,421,422};
    Solution sol;
    int sum = 9864;
    cout << sol.coinChange(coins, sum);

    return 0;
}
