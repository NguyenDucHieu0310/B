#include <bits/stdc++.h>
using namespace std;

char Telephone(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'C') return '2';
    if (c >= 'D' && c <= 'F') return '3';
    if (c >= 'G' && c <= 'I') return '4';
    if (c >= 'J' && c <= 'L') return '5';
    if (c >= 'M' && c <= 'O') return '6';
    if (c >= 'P' && c <= 'S') return '7';
    if (c >= 'T' && c <= 'V') return '8';  
    return '9'; 
}

bool is_palindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l; --r;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s, number = "";
        getline(cin, s);
        for (char c : s) number += Telephone(c);
        cout << (is_palindrome(number) ? "YES" : "NO") << endl;
    }
}