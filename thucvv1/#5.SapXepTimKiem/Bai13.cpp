// ĐỀ BÀI
//
// Cho một dãy gồm n thanh gỗ, mỗi thanh có độ cứng a[i].
// Bạn cần chọn các thanh gỗ sao cho độ cứng của mỗi thanh được chọn nhỏ hơn độ cứng của thanh trước đó đúng 1 đơn vị.
// Hỏi có thể chọn tối đa bao nhiêu thanh gỗ theo quy tắc trên?
//
// INPUT
// - Dòng đầu tiên chứa số nguyên n — số lượng thanh gỗ.
// - Dòng tiếp theo chứa n số nguyên a[i] — độ cứng của từng thanh gỗ.
//
// OUTPUT
// In ra số lượng thanh gỗ tối đa có thể chọn theo quy tắc trên.
//
// VÍ DỤ
//
// Input
// 5
// 5 4 3 2 1
//
// Output
// 5
//
// Input
// 6
// 6 5 5 4 3 2
//
// Output
// 5
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int& x : a)
        cin >> x;
    sort(a, a + n, greater<int>());
    int doCung = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        doCung = min(doCung - 1, a[i]);
        if (doCung >= 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
