#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="(()[][]{}){}{}[][]({[]()})";
    
    int n=s.length();
    if(n%2==1){cout<<0; return 0;}
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='{'||s[i]=='('||s[i]=='[') st.push(s[i]);
        else if(s[i]=='}'&&st.top()=='{' || s[i]==']'&&st.top()=='['  || s[i]==')'&&st.top()=='(') st.pop();
        else {cout<<0; return 0;}
    }
    if(st.empty()) cout<<1;
    else cout<<0;
}