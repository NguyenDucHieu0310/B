#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long int,long long int> &a, pair<long long int, long long int>&b){
    return a.first > b.first;
}

void C(vector<pair<long long int, long long int>>&pos, int k, long long int &res){
    int i=0;
    while(i<pos.size()){
        res+=2*pos[i].first;
        int cur=k;
        //cout<<i<<" "<<res<<endl;
        while(cur-pos[i].second>=0) {
            //cout<<i<<"haha "<<res<<endl;
            if(i==pos.size()-1) return;
            cur=cur-pos[i++].second; 
        }
        pos[i].second-=cur;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long int n; long long int k;
    cin >> n >> k;
    vector<pair<long long int, long long int>> pos;
    vector<pair<long long int, long long int>> neg;
    int x, m;
    long long int res=0;
    for(int i = 0; i < n; i++){
        cin >> x >> m;
        if(x > 0){
            res+=2 * (m/ k ) * x;
            if(m%k!=0)            pos.push_back(make_pair(x, m%k));
        }
        else if(x < 0){
            x=-x;
            res+=2*(m/k)*x;
            if(m%k!=0) neg.push_back(make_pair(x, m%k));
        }
    }
    
    
    sort(pos.begin(), pos.end(), cmp);
    sort(neg.begin(), neg.end(), cmp);
    for(auto x: pos) cout<<x.first<<" "<<x.second<<endl;
    C(pos, k, res);
    C(neg, k, res);
    cout<<res;
}
