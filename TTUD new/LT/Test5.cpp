#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    cout << (set<char>(s.begin(), s.end()).size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
    return 0;
}