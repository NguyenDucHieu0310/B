// ĐỀ BÀI

// Cho mảng số nguyên a gồm n phần tử và một số nguyên k.  
// Hãy chia mảng thành các nhóm (segment) thỏa mãn điều kiện:

// - Các phần tử trong cùng một nhóm phải có giá trị "liên tiếp nhau", nghĩa là hiệu giữa hai phần tử kề nhau (sau khi sắp xếp tăng dần) không vượt quá k.
// - Nếu tại vị trí nào mà a[i] - a[i-1] > k, thì bắt buộc phải tách ra thành một nhóm mới.

// Hãy tính số nhóm thu được.

// INPUT
// - Dòng 1: hai số nguyên n, k — số phần tử của mảng và ngưỡng chênh lệch k.
// - Dòng 2: n số nguyên — các phần tử của mảng a.

// OUTPUT
// - In ra một số nguyên duy nhất — số nhóm thu được.

// VÍ DỤ

// Ví dụ 1
// Input
// 5 2
// 1 2 4 7 9

// Output
// 2
// Giải thích:
// Sắp xếp: [1, 2, 4, 7, 9]
// - Nhóm 1: [1, 2, 4] vì hiệu liên tiếp ≤ 2
// - Nhóm 2: [7, 9] vì 7 - 4 > 2 → phải tách nhóm

// Ví dụ 2
// Input
// 6 3
// 10 1 4 7 13 16

// Output
// 2
// Giải thích:
// Sắp xếp: [1, 4, 7, 10, 13, 16]
// - Nhóm 1: [1, 4, 7, 10, 13] (các hiệu ≤ 3)
// - Nhóm 2: [16] (16 - 13 > 3 → phải tách nhóm)


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
