/*
Đề bài:
Có N công việc, mỗi công việc i có:
- id_i: mã công việc (không quan trọng cho thuật toán)
- deadline_i: thời hạn cuối cùng để hoàn thành công việc (tính bằng đơn vị ngày, bắt đầu từ 1)
- profit_i: lợi nhuận khi hoàn thành công việc i đúng hạn.

Mỗi công việc mất đúng 1 ngày. Hãy lập lịch sao cho tổng lợi nhuận là lớn nhất.

Input:
- Dòng 1: số nguyên n (1 ≤ n ≤ 10^5)
- N dòng tiếp theo: mỗi dòng gồm ba số nguyên: id_i, deadline_i, profit_i

Output:
- Một số nguyên: tổng lợi nhuận lớn nhất có thể đạt được.

Ví dụ:

Input:
4
1 4 20
2 1 10
3 1 40
4 1 30

Output:
100

Giải thích:
- Sắp xếp công việc theo lợi nhuận giảm dần: (3,1,40), (4,1,30), (1,4,20), (2,1,10)
- Lịch làm việc:
  - Ngày 1: công việc 3 → lợi nhuận 40
  - Ngày 2: công việc 4 → lợi nhuận 30
  - Ngày 4: công việc 1 → lợi nhuận 20
- Tổng lợi nhuận = 40 + 30 + 20 = 90
- (Lưu ý: kết quả thực tế phụ thuộc vào cách ưu tiên ngày trống sớm nhất trước deadline.)
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a + n, greater<pair<int, int>>());
    vector<bool> used(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = a[i].second - 1; j >= 0; j--) {
            if (!used[j]) {
                ans += a[i].first;
                used[j] = true;
                break;
            }
        }
    }
    cout << ans << endl;
}