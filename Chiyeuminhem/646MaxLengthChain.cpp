class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[1]<p2[1]) return true;
        if(p1[1]==p2[1]) return p1[0]<p2[0];
        return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int res=0, i=1, prev=0;
        while(i<pairs.size()){
            
            if(pairs[prev][1]< pairs[i][0]) {
                prev=i; i++;res++;
            }
            else i++;

        }    
        return res+1; 
    }
};