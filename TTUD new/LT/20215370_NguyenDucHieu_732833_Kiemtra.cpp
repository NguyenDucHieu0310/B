//Nguyen Duc Hieu - 20215370
#include<bits/stdc++.h>
using namespace std;
#define ff cout
string tab(int i70){
    return string (i70,' ');
}

struct S70{
    string tenhang70;
    string dvtinh70;
    int soluong70, dongia70;
    int tien70;
    int res70;
    
};
struct P70{
    string ten70, maphieu70;
    int day70, month70, year70;
    int sohang70;
    vector<S70> hang70; 

    int tienhang70, trans70;
    int money70; 
      
};
void print(S70 s){
   cout << left
        << setw(20) << s.tenhang70
        << setw(10) << s.dvtinh70
        << setw(10) << s.soluong70
        << setw(15) << s.dongia70
        << setw(15) << s.soluong70*s.dongia70
        << setw(15) << s.tien70
        << setw(15) << s.tien70+(s.soluong70*s.dongia70)
        << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n70;
    cout<<"Kip 9h14-11h45 Tuan 18 - Ngay 06.01.2024"<<endl<<"Kiem Tra thuc hanh - Quan Ly Phieu xuat"<<endl;
    cout<<"Nguyen Duc Hieu - 5370 - 7732833 - 2023.1"<<endl;
    cout<<"Nhap so Phieu Xuat: "<<endl;
    
    cin>>n70;
    vector<P70> t(n70);
    cout<<"**  CHUONG TRINH QUAN LY PHIEU XUAT **"<<endl;
    cout<<"**1 NHAP CAC PHIEU XUAT MAT HANG **"<<endl;
    cout<<"**2 IN RA KET QUA PHIEU XUAT VA MAT HANG**"<<endl;
    cout<<"********************************";
    cout<<"Nhap lua chon cua ban"<<endl;
   
        cout<<"BAN DA CHON NHAP PHIEU XUAT VA MAT HANG"<<endl;
        for(int i=0; i< n70; i++){
            t[i].trans70=0;
            t[i].tienhang70=0;
            cout<<"Nhap thong tin Phieu Xuat "<<i+1<<":"<<endl;
            cout<<tab(4)<<"Ten kho hang:"<<endl;
            cin>>t[i].ten70;
            
            //cout<<tab(4)<<"Ma phieu xuat:"<<endl;
            //cin>>t[i].maphieu70;
            
            cout<<"Ngay lap phieu xuat"<<endl;
            cout<<tab(4)<<"Ngay:"<<endl;
            cin>>t[i].day70;        
            cout<<tab(4)<<"Thang:"<<endl;
            cin>>t[i].month70;        
            cout<<tab(4)<<"Nam:"<<endl;
            cin>>t[i].year70;        
            cout<<tab(4)<<"So mat hang:"<<endl;
            cin>>t[i].sohang70;        
            cout<<tab(4)<<"Nhap ds cac mat hang"<<endl;
            
            for(int j=0; j<t[i].sohang70; j++){
                S70 s;
                cout<<tab(4)<<"Mat hang thu"<<j+1<<endl;
                cout<<tab(8)<<"Ten mat hang:";cout<<endl;
                cin>>s.tenhang70; 
                cout<<tab(8)<<"Don vi tinh:";cout<<endl;
                cin>>s.dvtinh70; 
                cout<<tab(8)<<"So luong:";cout<<endl;
                cin>>s.soluong70; 
                cout<<tab(8)<<"Don gia:";cout<<endl;
                cin>>s.dongia70; 
                if (s.dvtinh70 =="Thung"){
                    if(s.soluong70<=10) s.tien70=50;
                    else if(s.soluong70<=30) s.tien70=75;
                    else if(s.soluong70<=50) s.tien70=100;
                    else s.tien70=150;
                }
                else{
                    if(s.soluong70<=50) s.tien70=30;
                    else s.tien70=75;
                }
                s.res70=s.soluong70*s.dongia70;
                t[i].trans70+=s.tien70;
                t[i].tienhang70+=s.res70;   
                t[i].hang70.push_back(s);
                        
            }   
            cout<<"So tien da thanh toan";cout<<endl;
            
            cin>>t[i].money70;

        }
        cout<<"Ban da nhap thanh cong!"<<endl<<"Bam phim bat ky de tiep tuc!"<<endl<<"Nguyen Duc Hieu - 5370 - 7732833 - 2023.1"<<endl;
    
        cout<<"Ban da chon IN RA PHIEU XUAT!"<<endl<<"Nguyen Duc Hieu - 5370 - 7732833 - 2023.1"<<endl;

        for(int i=0; i<n70; i++){
            cout<<"Ten kho hang: "<<t[i].ten70<<endl;
            cout<<"Ngay "<<t[i].day70<<" Thang "<<t[i].month70<<" Nam "<<t[i].year70<<endl;
            cout<<tab(4)<<"So mat hang: "<<t[i].sohang70<<endl;
            cout<<tab(4)<<"Da thanh toan: "<<t[i].money70<<endl;
            cout<<tab(4)<<"Tong thanh tien  "<<t[i].tienhang70<<endl;
            cout<<tab(4)<<"Tong van chuyen : "<<t[i].trans70<<endl;
            cout<<tab(4)<<"Tong phai thanh toan: "<<t[i].trans70+t[i].tienhang70<<endl;
            cout<<tab(4)<<"Tinh trang thanh toan: "<<endl;
            int c70=t[i].money70-(t[i].trans70+t[i].tienhang70);
            cout<<"Tinh trang thanh toan"<<endl;
            if(c70<0){
                cout<<tab(4)<<"Thanh toan thieu so tien : "<<abs(c70)<<endl;
            }
            else cout<<tab(4)<<"Chuyen Phieu Xuat sau so tien : "<<c70<<endl;
            cout<<tab(8)<<"Chi tiet cac mat hang:"<<endl;
            cout<<"Ten Mat Hang"<<tab(8)<<"DonVT"<<tab(5)<<"SoL"<<tab(7)<<"don gia"<<tab(8)<<"Thanh tien"<<tab(5)<<"Van chuyen"<<tab(5)<<"TCong"<<endl;
            for(auto M:t[i].hang70) print(M);
        }
    
    }
