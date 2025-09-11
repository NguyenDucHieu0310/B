#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
         int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    long long total = 1LL * n * (n-1) * (n-2) / 6;

    unordered_map<int,int> freq;
    for(int x : a) freq[x]++;

    long long all_different = 0;
    vector<int> counts;
    for(auto &p : freq) counts.push_back(p.second);

    int k = counts.size();
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            for(int t=j+1;t<k;t++){
                all_different += 1LL * counts[i] * counts[j] * counts[t];
            }
        }
    }

    cout << total - all_different << "\n";
}
    
    return 0;
}