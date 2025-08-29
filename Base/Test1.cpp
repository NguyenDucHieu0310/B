#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K; 
    cin >> K;
    
    while (K--) {
        string a, b, c; 
        cin >> a >> b >> c;

        vector<char> digits;
        for (char ch : a) digits.push_back(ch);
        for (char ch : b) digits.push_back(ch);
        for (char ch : c) digits.push_back(ch);

        sort(digits.begin(), digits.end(), greater<char>());
        
        string result;
        bool leading_zero = true;
        for (char ch : digits) {
            if (ch != '0') leading_zero = false; 
            if (!leading_zero || result.empty() && ch == '0' && digits.size() == 1) {
                result += ch; 
            }
        }
 
        if (result.empty()) result = "0";

        cout << result << endl;
    }
    
    return 0;
}