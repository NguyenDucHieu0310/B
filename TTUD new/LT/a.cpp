#include<bits/stdc++.h>
using namespace std;

vector<int> input() {
    vector<int> v;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int num;
    while (iss >> num) {
        v.push_back(num); 
    }
    sort(v.begin(), v.end());
    return v;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> v1=input();
    vector<int> v2=input();
    vector<int> v3=input();
    while(!v3.empty() && !v1.empty() && !v2.empty() && v3[0]< v1[0]+v2[0]) v3.erase(v3.begin());
    while(!v3.empty() && !v1.empty() && !v2.empty() && v3[v3.size()-1]< v1[0]+v2[v2.size()-1]) v2.pop_back();
    while(!v3.empty() && !v1.empty() && !v2.empty() && v3[v3.size()-1]< v2[0]+v1[v1.size()-1]) v1.pop_back();
    for(auto x: v1) cout<<x<<" ";
    cout<<endl;
    for(auto x: v2) cout<<x<<" ";
    cout<<endl;
    for(auto x: v3) cout<<x<<" ";
    cout<<endl;
    
}