#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2) {return p1.second<p2.second;}
int MaxSegmentDisjoint(vector<pair<int,int>>&seg){
    sort(seg.begin(), seg.end(), comp);
    int prevChoose=-1;
    int count=0;
    for(auto p: seg){
        if(p.first>prevChoose){
            prevChoose=p.second;
            count++;
        }
    }
    return count;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, a, b;
    cin>>n;
    vector<pair<int, int>> seg;
    while(n--){  
        cin>>a>>b;
        seg.push_back(make_pair(a,b));
    }
    cout<<MaxSegmentDisjoint(seg);
}