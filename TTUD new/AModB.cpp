#include<bits/stdc++.h>
using namespace std;
const unsigned long long modul=1e9+7;
unsigned long long mod(unsigned long long a, unsigned long long b){    
    a=a%modul;
    unsigned long long  res=1;
    while(b>0){
        if(b%2==1)      res=(res*a)%modul;
        b=b>>1;
        a=(a*a)%modul;
    }
    return res;
}
int main(){
    unsigned long long a,b;
    cin>>a>>b;
    cout<<(mod(a,b));
}