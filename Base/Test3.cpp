#include <bits/stdc++.h>
using namespace std;

int digitSum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int year;
    cin >> year;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeap(year)) daysInMonth[1] = 29;

    int total = 0;
    int yS = digitSum(year);
    for (int month = 1; month <= 12; ++month) {
        int mS = digitSum(month);
        for (int day = 1; day <= daysInMonth[month-1]; ++day) {
            int dS = digitSum(day);
            total += dS + mS + yS;
        }
    }
    cout << total << '\n';
}