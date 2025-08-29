#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
      } else {
        return n * factorial(n - 1);
      }
    }
    string getPermutation(int n, int k) {
        int x=k-1;
        vector<int>num(n);
        for(int i=0;i<n;i++) num[i]=i+1;
        string result="";

        
        while(n>0){
            int i=x/factorial(n-1);
            x=x%factorial(n-1);
            result+=(num[i]+'0');
            num.erase(num.begin()+i);
            n--;
        }
        return result;
        
    }
};
int main() {
    Solution solution;
    int n ,k;
    cout<<"Nhap lan luot n va k";
    cin>>n>>k;
    string permutation = solution.getPermutation(n, k);
    cout << "Permutation: " << permutation << endl;

    return 0;
}
