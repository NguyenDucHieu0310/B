#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        int countPair=0;
        int countAlone=0;
        for(char c: s){
            if(map[c]==1){
                countPair++;
                map[c]=0;
                countAlone--;
            }
            else{
                map[c]=1;
                countAlone++;
            }

        }
        return (countAlone==0)?countPair*2:(countPair*2+1);
    }
};
int main(){
    string s;
    cin>>s;
    Solution sol;
    cout<<sol.longestPalindrome(s);
}