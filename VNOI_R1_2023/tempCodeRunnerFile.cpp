#include<bits/stdc++.h>
using namespace std;

int Run(){
    int a, x, b, y;
    cin>>a>>x>>b>>y;
    if(a>b&&x>y) return 1;
    if(a<b&&x<y) return 2;
    if(a==b&&x==y) return 0;
    if(a<=9*x){
        if(b<=9*y){
            if(a>b) return 1;
            if(a==b) return 0;
            if(a<b) return 2;
        }
        if(90*(b+y)>100*a) return 1;
        if(90*(b+y)==100*a) return 0;
        return 2;

    }
    if(b<=9*y){
        if(100*b>90*(a+b)) return 1;
        if(100*b<90*(a+b)) return 2;
        return 0;
    }
    if(a+x>b+y) return 1;
    if(a+x==b+y) return 0;
    return 2;    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin>>T;
    while(T--){
        if (Run()==1) cout<<"Megumin"<<endl;
        else if (Run()==2) cout<<"Yunyun"<<endl;
        else cout<<"Draw"<<endl;
    }
    return 0;
}