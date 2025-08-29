#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int num_vowels = 0;
        for (auto x : s) {
            if (isVowel(x)) {
                num_vowels++;
            }
        }
        if (num_vowels < 2) {
            return s;
        }
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isVowel(s[left])) {
                left++;
            } else {
                while (right > left) {
                    if (!isVowel(s[right])) {
                        right--;
                    } else {
                        swap(s[left], s[right]);
                        left++;
                        right--;
                        break;
                    }
                }
            }
        }
        return s;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    string a = sol.reverseVowels(s);
    cout << a << endl;
    return 0;
}
