#include<bits/stdc++.h>
using namespace std;
string Multiply(string s1,string s2){
    int m=s1.length(), n=s2.length();
    string res(m+n,'0');
    for(int i=m-1;i>=0;i--){
        int carry=0;
        for(int j=n-1;j>=0;j--){
            int p=(s1[i]-'0')*(s2[j]-'0')+(res[i+j+1]-'0')+carry;
            carry=p/10;
            res[i+j+1]=(p%10)+'0';
        }
        res[i]+=carry;
    }
    int i=0;
    while(res[i]=='0') i++;
    return res.substr(i, m+n);
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<Multiply(a,b);
}