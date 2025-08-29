#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (sum % n != 0) {
            return -1;
        }
        int req = sum / n;
        int ret = 0;
        int extra = 0;
        for (int i = 0; i < n; i++) {
            int x = machines[i];
            //extra += (x - req);
            ret = max({ret, x - req, abs(extra)});
        }
        return ret;


    }
};
int main() {
    Solution solution;
    vector<int> intervals = {7,5,6,0,4};
    int result = solution.findMinMoves(intervals);
    cout<<"Minimum moves: " << result << endl;

    return 0;
}