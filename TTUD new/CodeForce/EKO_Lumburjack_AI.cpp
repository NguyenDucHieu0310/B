#include<bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>& trees, int M) {
    long long total = 0;
    for(int i = 0; i < trees.size(); i++) {
        if(trees[i] > mid) {
            total += trees[i] - mid;
        }
    }
    return total >= M;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> trees(N);
    for(int i = 0; i < N; i++) {
        cin >> trees[i];
    }
    int low = 0, high = 1e9;
    while(high - low > 1) {
        int mid = (low + high) / 2;
        if(check(mid, trees, M)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << low << endl;
    return 0;
}
