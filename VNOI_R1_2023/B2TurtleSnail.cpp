#include <bits/stdc++.h>
using namespace std;

double finish_time(double vt, double vs) {
    // vt: velocity of turtle (cm/min)
    // vs: velocity of snail on shell (cm/min)
    double t1 = 100.0 / (vt + vs);
    double t_thresh = 10.0 / vs;
    if (t1 <= t_thresh) {
        return t1;
    } else {
        return max(90.0 / vt, t_thresh);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    const double EPS = 1e-9;
    while (T--) {
        int tm, sm, ty, sy;
        cin >> tm >> sm >> ty >> sy;
        double t_meg = finish_time((double)tm, (double)sm);
        double t_yun = finish_time((double)ty, (double)sy);

        if (fabs(t_meg - t_yun) < EPS) cout << "Draw\n";
        else if (t_meg < t_yun) cout << "Megumin\n";
        else cout << "Yunyun\n";
    }
    return 0;
}
