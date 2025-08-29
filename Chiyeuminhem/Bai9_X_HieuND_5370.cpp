#include <bits/stdc++.h>
using namespace std;
//Nguyen Duc Hieu -5370-732833
void genS(vector<int>&nums, vector<int>& cur, int pos, int len){
    //nếu dãy con hiện tại độ dài len, in ra các phần tử
    if(cur.size()==len){                  
        for(int x: cur) cout<<x<<" ";
        cout<<endl;
    }
    //nếu chưa đủ thì lấy từ vị trí hiện tại rồi thêm vào cur, gọi đệ quy//Nguyen Duc Hieu -5370-732833
    else{
        for(int i = pos; i < nums.size()-(len-cur.size())+1;i++){
            cur.push_back(nums[i]);
            genS(nums, cur, i+1, len);
            cur.pop_back();
        }
    }
}
int main(){
    vector<int> nums={1, 3, 4, 2};
    int n=nums.size();   // n là độ dài
    vector<int> cur;   // dãy con hiện tại
    for(int len=1; len<=n; len++){  // lấy len từ 1 đến n;
        genS(nums, cur, 0, len);    // tìm các dãy con độ dài len
    }
}