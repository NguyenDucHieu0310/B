/*Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2*/
#include<bits/stdc++.h>
using namespace std;
void backtrack(vector<vector<int>>&res, vector<int>&cur, int id,int k, int n){
    if(cur.size()==k) res.push_back(cur);
    else{
        for(int i=id;i<=n-k+cur.size()+1;i++){
            cur.push_back(i);
            backtrack(res,cur,i+1,k,n);
            cur.pop_back();
        }
    }
}
int main(){
    int k,n; cin>>k>>n;
    vector<vector<int>> res;
    vector<int> cur;
    backtrack(res,cur,1,k,n);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<k;j++) 
        cout<<res[i][j]<<" ";
        cout<<endl;
    }
}