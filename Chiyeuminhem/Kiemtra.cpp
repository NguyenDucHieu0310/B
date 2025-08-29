//Nguyen Duc Hieu - 20215370
#include<bits/stdc++.h>
using namespace std;
struct P70{
    string ten70, maphieu70,;
    int day70, month70, year70;
    int sohang70;
    vector<Mathang>
    
};
struct S70{
    string tenhang70, dvtinh70;
    int soluong70, dongia70;
}
#include<bits/stdc++.h>
using namespace std;
struct ShoppeeSalesSAPSAN11_11{
    string customer_id;
    string product_id;
    int price;
    string shop_id;
    string time_point;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<ShoppeeSalesSAPSAN11_11> shop;
    int revenue=0;
    string line;
    map<string,int>revenue_shop;
    map<pair<string, string>, int> mecungtinhyeu;
    while(getline(cin,line)&&line!="#"){
        istringstream iss(line);
        ShoppeeSalesSAPSAN11_11 t;
        iss>>t.customer_id>>t.product_id>>t.price>>t.shop_id>>t.time_point;
        revenue+=t.price;
        revenue_shop[t.shop_id]+=t.price;
        mecungtinhyeu[{t.customer_id, t.shop_id}]+=t.price;
        shop.push_back(t);
    }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n70;
    cout<<"Kip 9h14-11h45 Tuan 18 - Ngay 06.01.2024"<<endl<<"Kiem Tra thuc hanh - Quan Ly Phieu xuat"<<endl;
    cout<<"Nguyen Duc Hieu - 5370 - 7732833 - 2023.1"<<endl;
    cout<<"Nhap so Phieu Xuat: "<<endl;
    
    cin>>n70;
    
}