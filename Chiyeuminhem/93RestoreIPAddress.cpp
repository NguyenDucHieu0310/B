#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(string s){
        int n=s.size();
        if(n==1) return true;
        if(n>3||s[0]=='0') return false;
        int val=stoi(s);
        return (val<=255);
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        if(n>12) return ans;
        for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        for(int k=1;k<=3;k++)
        if(i+j+k<n&&i+j+k+3>=n){
            string a=s.substr(0,i), b=s.substr(i,j), c=s.substr(j+i,k),d=s.substr(i+j+k,n);
            if(check(a)&&check(b)&&check(c)&&check(d)) 
            ans.push_back(a+"."+b+"."+c+"."+d);
        }
        
        return ans;

    }
};
int main(){
    string s;
    cout<<"Nhap chuoi ki tu can check IP"<<endl;
    cin>>s;
    Solution solution;
    vector<string> result = solution.restoreIpAddresses(s);

    // Print the valid IP addresses
    for (const auto& ip : result) {
        cout << ip << endl;
    }

    return 0;
}