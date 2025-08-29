#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, u; 
    priority_queue<int, vector<int>, greater<int>> q;
    cin>>a;
    while(a--){
        cin>>u;
        q.push(u);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}