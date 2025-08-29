#include <bits/stdc++.h>
using namespace std;

vector<int> Solve(const string &s) {
    int n = s.size();
    vector<int> res(n, 0);
    for (int i = 1; i < n; i++) {
        int j = res[i - 1];
        while (j > 0 && s[i] != s[j]) j = res[j - 1];
        if (s[i] == s[j]) j++;
        res[i] = j;
    }
    return res;
}


int minLength(const string &s) {
    int n = s.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0; 
    
    for (int i = n - 1; i >= 0; i--) {
 
        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j - i + 1);
            int len = j - i + 1;
            
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
            
  
            vector<int> res = Solve(sub);
            int period = len - res[len - 1];
            if (len % period == 0 && len / period > 1) {
                int k = len / period;
                string v = sub.substr(0, period);
                int vLen = minLength(v);
                int numLen;
                if(k<10) numLen=1;
                else if(k<100) numLen=2;
                else if(k<1000) numLen=3;
                dp[i] = min(dp[i], numLen + 2 + vLen + dp[j + 1]);
            }
            
            dp[i] = min(dp[i], len + dp[j + 1]);
        }
    }
    return dp[0];
}

int main() {
    string s;
    int caseNum = 1;    
    while (true) {
        cin >> s;
        if (s == "0") break;
        cout << "Case " << caseNum << ": " << minLength(s) << endl;
        caseNum++;
    }
    
    return 0;
}