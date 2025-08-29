#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,res = 0;
    cin >>a>>b;
    while (b > 0) {
        res += a/b; 
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    cout <<res<< endl;
    return 0;
}