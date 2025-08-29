#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int k = 0;
    long long total_digits = 0;
    while (total_digits < n) {
        k++;
        total_digits += 9 * pow(10, k-1) * k;
    }
    
    k--;
    total_digits -= 9 * pow(10, k) * (k + 1);
    
    long long remaining = n - total_digits - 1;
    long long num_index = remaining / (k + 1);
    long long digit_index = remaining % (k + 1);
    
    long long number = pow(10, k) + num_index;
    string num_str = to_string(number);
    
    cout << num_str[digit_index] << endl;
    
    return 0;
}