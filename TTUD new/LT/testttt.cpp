#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int n, x, y, c;
    cin >> n;
    vector<long long int> tra (3*n);// vector tạm thời để lưu giá trị n cặp ( x,y,c )
    long long int maxsize = 0;//lưu giá trị size của ma trận
    for(int i = 0; i < n; i++){
        cin >> x >> y >> c;
        maxsize = max({maxsize, x, y});
        tra[3*i]=x;
        tra[3*i+1]=y;
        tra[3*i+2]=c;
    }
    maxsize++;// cộng 1 do bắt đầu từ 0

    vector<vector<long long int>> g(maxsize, vector<long long  int>(maxsize, 0));

    for(long long int i = 0; i < n; i ++)
        g[tra[3*i]][tra[3*i + 1]] = tra[3*i + 2];// chuyển các cặp 3 số từ tra sang g;
    
    for(auto &x:g){
        for(auto k:x)
        cout<<k<<" ";
        cout<<endl;
    }
    for(long long int i = 1; i < maxsize; i++){
        for(long long int j = 1; j < maxsize; j++){
            g[i][j] += max(g[i - 1][j], g[i][j - 1]);
        }
    }
    cout<<"sau khi dp"<<endl;
    for(auto &x:g){
        for(auto k:x)
        cout<<k<<" ";
        cout<<endl;
    }
    cout <<"res"<< g[maxsize - 1][maxsize - 1];
}
