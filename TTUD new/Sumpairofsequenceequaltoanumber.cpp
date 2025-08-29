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
int main(){
    int n,M; cin>>n>>M;
    vector<int> nums;
    for(int i=0;i<n;i++) {int x;cin>>x;nums.push_back(x);}
    sort(nums.begin(),nums.end());
    int left=0, right=n-1, count=0;
    while(left<right){
        int sum=nums[left]+nums[right];
        if(sum==M) {count++;left++;}
        else if(sum>M) right--;
        else left++;
    }
    cout<<count;
}