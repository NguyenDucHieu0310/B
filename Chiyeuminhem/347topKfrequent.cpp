#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int num : nums) map[num]++;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(auto it=map.begin(); it!=map.end(); it++){
            q.push(make_pair(it->second, it->first));
            if(q.size()>k) q.pop();
        }
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
int main(){
    int size, k; cin>>size>>k;
    vector<int> nums(size);
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    Solution sol;
    for(auto x: sol.topKFrequent(nums, k)) cout<<x<<" ";
}