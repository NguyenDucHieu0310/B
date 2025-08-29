#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& s) {
        sort(s.begin(), s.end());
        

        int count =0, i=1, prev=0;
        while (i<s.size()){
            if(s[prev][1]>s[i][0]){
                s[prev][1]=min(s[prev][1], s[i][1]) ;                
            }
            else if(s[prev][1]< s[i][0]){
                count++;
                 prev=i;                
            }
            i++;
        }
        return count+1;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> intervals = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};
    int result = solution.findMinArrowShots(intervals);

    cout << "Minimum arrows needed: " << result << endl;

    return 0;
}