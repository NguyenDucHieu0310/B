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

// Function to compute minimum encoded length for a string (used for repeating units)
int minEncodedLength(const string &s) {
    int n = s.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0; // Base case: empty string
    
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
                int numLen = (len == 1) ? 0 : (len < 10 ? 1 : (len < 100 ? 2 : (len < 1000 ? 3 : 4)));
                dp[i] = min(dp[i], numLen + 1 + dp[j + 1]);
            }
            
            // Case 2: Try to find repeated patterns
            vector<int> pi = computeKMP(sub);
            cout<<"i: "<<i<<"j: "<<j<<endl;
            for(auto c:pi) cout<<c<<" ";
            cout<<endl;
            int period = len - pi[len - 1];
            cout<<"len: "<<len<<" pi(len-1): "<<pi[len-1]<<" period: "<<period<<endl;
            if (len % period == 0 && len / period > 1) {
                int k = len / period;
                string unit = sub.substr(0, period);
                int unitLen = minEncodedLength(unit); // Recursively compute min length of unit
                int numLen = (k < 10 ? 1 : (k < 100 ? 2 : (k < 1000 ? 3 : 4)));
                dp[i] = min(dp[i], numLen + 2 + unitLen + dp[j + 1]);
            }
            
            // Case 3: No compression
            dp[i] = min(dp[i], len + dp[j + 1]);
        }
    }
    cout<<"DP:  ";
    for(auto x: dp) cout<<x<<" ";
    cout<<endl;
    return dp[0];
}

int main() {
    string s;
    int caseNum = 1;
    
    while (true) {
        cin >> s;
        if (s == "0") break; // Exit on input "0"
        
        // Output the result for the current test case
        cout << "Case " << caseNum << ": " << minEncodedLength(s) << endl;
        caseNum++;
    }
    
    return 0;
}
/*
4
4 4
1 6
1 38
1 39
*/
