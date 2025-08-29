#include<bits/stdc++.h>
using namespace std;

void processCommands(const vector<pair<string, int>>& commands) {
    double x = 0.0, y = 0.0, alpha = 0.0;

    for (const auto& command : commands) {
        const string& cmd = command.first;
        int value = command.second;
        if (cmd == "fd") {
            x += value * cos(alpha);
            y += value * sin(alpha);
        } else if (cmd == "bk") {
            x -= value * cos(alpha);
            y -= value * sin(alpha);
        } else if (cmd == "lt") {
            alpha += value * M_PI / 180.0; 
        } else if (cmd == "rt") {
            alpha -= value * M_PI / 180.0; 
        }
    }
    double distance = sqrt(x * x + y * y);
    cout << static_cast<int>(round(distance)) << endl;   
}

int main(){
    int N;
    double alpha;
    cin>>N;
    while(N--){
        int k;
        cin>>k;
        vector<pair<string, int>> commands(k);
        for (int i = 0; i < k; ++i) {
            cin >> commands[i].first >> commands[i].second;
        }
        processCommands(commands);
    }
}