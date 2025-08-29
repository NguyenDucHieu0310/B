#include<bits/stdc++.h>
using namespace std;
int totalcall=0,incorrectCallNum=0;
map<string,int> calltime,callnum;
int isCorrect(string tel){
    if (tel.length()!=10) return 0;
    for(int i=0;i<tel.length();i++){
        if (tel[i]<'0'||tel[i]>'9') return 0;
    }
    return 1;
}
int duration(string st, string et){

    int stime = (st[0]*10+st[1])*3600 + (st[3]*10+st[4])*60 + st[6]*10 + st[7];

    int etime = (et[0]*10+et[1])*3600 + (et[3]*10+et[4])*60 + et[6]*10 + et[7];

    return etime - stime;

}


void input(){
    string type, from_tel,to_tel, date,start,end;
    do{
       cin>>type;
       if(type=="#") continue;
       cin>>from_tel>>to_tel>>date>>start>>end;
       if(!isCorrect(from_tel)||!isCorrect(to_tel)) incorrectCallNum++;
       else totalcall++;
       callnum[from_tel]++;
       calltime[from_tel]+=duration(start,end);
    } while(type!="#");
}
void solve(){
    string type,tel;
    do{
        cin>>type;
        if (type=="#") continue;
        if(type=="?check_phone_number") cout<< (incorrectCallNum==0)<<endl;
        else if(type=="?number_total_calls") cout<<totalcall<<endl;
        else if(type=="?number_calls_from"){
            cin>>tel;
            cout<<callnum[tel]<<endl;
        }
        else if(type=="?count_time_calls_from"){
            cin>>tel;
            cout<<calltime[tel]<<endl;
        }

    } while(type!="#");

}
int main(){
    ios_base :: sync_with_stdio(0);

    cin.tie(0); cout.tie(0);
    
    input();
    solve();
    return 0;
}