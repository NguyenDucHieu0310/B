// ĐỀ BÀI

// Cho 2 mảng số nguyên a (kích thước n) và b (kích thước m).  
// Ta muốn ghép các phần tử của a với các phần tử của b theo quy tắc:

// - Một phần tử a[i] có thể ghép với b[j] nếu a[i] > b[j].
// - Mỗi phần tử chỉ được sử dụng nhiều nhất một lần.
// - Việc ghép được thực hiện theo cách tham lam từ trái sang phải.

// Hãy tính số cặp ghép được nhiều nhất theo quy tắc trên.

// INPUT
// - Dòng 1: hai số nguyên n, m — kích thước mảng a và b.
// - Dòng 2: n số nguyên — các phần tử của mảng a.
// - Dòng 3: m số nguyên — các phần tử của mảng b.

// OUTPUT
// - In ra một số nguyên duy nhất — số cặp ghép tối đa.

// VÍ DỤ

// Ví dụ 1
// Input
// 5 3
// 2 7 4 8 10
// 1 3 5

// Output
// 3

// Ví dụ 2
// Input
// 4 4
// 1 2 3 4
// 5 6 7 8

// Output
// 0


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int& x : a)
        cin >> x;
    for (int& x : b)
        cin >> x;
    int cnt = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            cnt++;
            i++;
            j++;
        } else {
            i++;
        }
    }
    cout << cnt << endl;
    return 0;
}
