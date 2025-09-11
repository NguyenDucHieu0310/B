// ĐỀ BÀI

// Cho mảng số nguyên a gồm n phần tử.  
// Bạn có thể chọn lần lượt các phần tử từ lớn đến nhỏ theo quy tắc sau:

// - Phần tử lớn nhất được lấy nguyên giá trị.
// - Phần tử tiếp theo (đứng sau trong thứ tự sắp giảm dần) chỉ được lấy giá trị = max(0, a[i] - i),  
//   trong đó i là chỉ số (bắt đầu từ 0 sau khi sắp xếp giảm dần).
// - Tiếp tục cho đến hết mảng.

// Hãy tính tổng giá trị thu được.

// INPUT
// - Dòng 1: số nguyên n — số phần tử của mảng.
// - Dòng 2: n số nguyên — các phần tử của mảng a.

// OUTPUT
// - In ra một số nguyên duy nhất — tổng giá trị lớn nhất có thể thu được.

// VÍ DỤ

// Ví dụ 1
// Input
// 5
// 2 2 2 2 2

// Output
// 10
// Giải thích:
// Sau khi sắp xếp giảm dần: [2, 2, 2, 2, 2]
// Giá trị lấy được = 2 + (2-1) + (2-2) + (2-3) + (2-4)
// = 2 + 1 + 0 + 0 + 0 = 3 → Tổng = 10

// Ví dụ 2
// Input
// 4
// 7 4 9 6

// Output
// 23
// Giải thích:
// Sắp xếp giảm dần: [9, 7, 6, 4]
// Giá trị = 9 + (7-1) + (6-2) + (4-3)
// = 9 + 6 + 4 + 1 = 20


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    long long sum = a[0];
    for (int i = 1; i < n; i++) {
        sum += max(0, a[i] - i);
    }
    cout << sum << endl;
    return 0;
}
