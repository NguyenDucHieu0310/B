#include<bits/stdc++.h>
using namespace std;
string getHint(string secret, string guess){
    map<char,int> c1,c2;
    int bull=0,cow=0;
    int n=secret.length();
    for(int i=0;i<n;i++){
        if(secret[i]==guess[i]) bull++;
        else{
            c1[secret[i]]++;
            c2[guess[i]]++;
        }
    }
    for(char i='0';i<='9';i++) {
        if(c1[i]>=c2[i]) cow+=c2[i];
        else   cow+=c1[i];
    }  
  string s=to_string(bull)+"A"+to_string(cow)+"B";
    return s;
}
int main(){
    string a, b;
    cin>>a>>b;
    string s=getHint(a,b);
    cout<<s;
}