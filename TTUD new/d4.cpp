#include <bits/stdc++.h>
using namespace std;

// Function to compute KMP failure function for a string
vector<int> computeKMP(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    int caseNum = 1;
    
    while (true) {
        cin >> s;
        if (s == "0") break; // Exit on input "0"
        
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] = min encoded length for s[i..n-1]
        dp[n] = 0; // Base case: empty string has encoded length 0
        
        // Process each starting index from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Try all possible ending indices j for substring s[i..j]
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                int len = j - i + 1;
                
                // Case 1: Check if substring is all same character
                bool same = true;
                for (int k = 1; k < len; k++) {
                    if (sub[k] != sub[0]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    // Encode as number + character, e.g., "aaa" -> "3a"
                    int numLen = (len == 1) ? 0 : (len < 10 ? 1 : (len < 100 ? 2 : (len < 1000 ? 3 : 4)));
                    dp[i] = min(dp[i], numLen + 1 + dp[j + 1]);
                }
                
                // Case 2: Try to find repeated patterns
                vector<int> pi = computeKMP(sub);
                int period = len - pi[len - 1];
                if (len % period == 0 && len / period > 1) {
                    // Substring can be encoded as k(sub) where k = len/period
                    int k = len / period;
                    string unit = sub.substr(0, period);
                    // Compute min encoded length of the unit
                    vector<int> unit_dp(period + 1, INT_MAX);
                    unit_dp[period] = 0;
                    for (int u = period - 1; u >= 0; u--) {
                        for (int v = u; v < period; v++) {
                            string sub_unit = unit.substr(u, v - u + 1);
                            int sub_len = v - u + 1;
                            // Check if sub_unit is all same character
                            bool sub_same = true;
                            for (int w = 1; w < sub_len; w++) {
                                if (sub_unit[w] != sub_unit[0]) {
                                    sub_same = false;
                                    break;
                                }
                            }
                            if (sub_same) {
                                int sub_numLen = (sub_len == 1) ? 0 : (sub_len < 10 ? 1 : (sub_len < 100 ? 2 : (sub_len < 1000 ? 3 : 4)));
                                unit_dp[u] = min(unit_dp[u], sub_numLen + 1 + unit_dp[v + 1]);
                            } else {
                                unit_dp[u] = min(unit_dp[u], sub_len + unit_dp[v + 1]);
                            }
                        }
                    }
                    // Encoded length: length of k + 2 (for "()") + encoded unit length
                    int numLen = (k < 10 ? 1 : (k < 100 ? 2 : (k < 1000 ? 3 : 4)));
                    dp[i] = min(dp[i], numLen + 2 + unit_dp[0] + dp[j + 1]);
                }
                
                // Case 3: No compression, each char as is
                dp[i] = min(dp[i], len + dp[j + 1]);
            }
        }
        
        // Output result for current test case
        cout << "Case " << caseNum << ": " << dp[0] << endl;
        caseNum++;
    }
    
    return 0;
}