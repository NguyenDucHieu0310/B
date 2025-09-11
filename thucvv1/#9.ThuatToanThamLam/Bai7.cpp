/*
Đề bài:
Cho N công việc, mỗi công việc i có thời gian bắt đầu s_i và kết thúc e_i. 
Hãy tìm số lượng công việc lớn nhất có thể chọn sao cho không có hai công việc nào trùng thời gian.

Input:
- Dòng 1: số nguyên n (1 ≤ n ≤ 10^5)
- N dòng tiếp theo: mỗi dòng gồm hai số nguyên s_i và e_i (0 ≤ s_i < e_i ≤ 10^9)

Output:
- Một số nguyên: số công việc tối đa có thể chọn.

Ví dụ:

Input:
3
1 3
2 5
4 6

Output:
2

Giải thích:
Chọn công việc (1,3) và (4,6) → không chồng nhau, tổng số công việc = 2.
*/


#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 1;
    int endTime = a[0].second;
    for (int i = 1; i < n; i++) {
        if (a[i].first > endTime) {
            ans++;
            endTime = a[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}