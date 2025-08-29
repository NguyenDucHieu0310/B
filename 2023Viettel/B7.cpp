// B7.cpp
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 merge_intervals_and_count(vector<pair<int64,int64>>& segs) {
    if (segs.empty()) return 0;
    sort(segs.begin(), segs.end());
    int64 res = 0;
    int64 curL = segs[0].first, curR = segs[0].second;
    for (size_t i = 1; i < segs.size(); ++i) {
        if (segs[i].first <= curR + 1) {
            curR = max(curR, segs[i].second);
        } else {
            res += (curR - curL + 1);
            curL = segs[i].first;
            curR = segs[i].second;
        }
    }
    res += (curR - curL + 1);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int64 X, Y;
    if (!(cin >> N >> X >> Y)) return 0;
    vector<pair<int64,int64>> segX, segY;
    for (int i = 0; i < N; ++i) {
        int64 xi, yi, wi;
        cin >> xi >> yi >> wi;
        int64 lx = max<int64>(1, xi - wi);
        int64 rx = min<int64>(X, xi + wi);
        if (lx <= rx) segX.emplace_back(lx, rx);
        int64 ly = max<int64>(1, yi - wi);
        int64 ry = min<int64>(Y, yi + wi);
        if (ly <= ry) segY.emplace_back(ly, ry);
    }
    int64 ax = merge_intervals_and_count(segX);
    int64 ay = merge_intervals_and_count(segY);
    // Covered cells = ax * Y + ay * X - ax * ay
    int64 tmp = (int64)ax * Y + (int64)ay * X - (int64)ax * ay;
    long long ans = (long long)tmp;
    cout << ans << '\n';
    return 0;
}