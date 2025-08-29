#include<bits/stdc++.h>
using namespace std;
int main()
{    int a=20, b=100;
    int &n=a;
    n = a++;
    n = &b;
cout << a <<","<<n<<endl;
}
/*
    while(true){
        cout<<u<<"<-";
        u=parent[u];
        if(u==-1) break;
    }
    */