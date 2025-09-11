// ĐỀ BÀI
//
// Cho hai mảng số nguyên đã được sắp xếp tăng dần gồm n phần tử (mảng b) và m phần tử (mảng c).
// Hãy thực hiện việc trộn hai mảng này thành một mảng mới theo thứ tự tăng dần.
// Khi trộn, in ra chỉ số phần tử được chọn (bắt đầu từ 1) và thuộc mảng nào (b hoặc c) theo thứ tự trộn.
//
// INPUT
// - Dòng đầu tiên chứa hai số nguyên n và m — số phần tử của mảng b và mảng c.
// - Dòng thứ hai chứa n số nguyên đã được sắp xếp tăng dần (mảng b).
// - Dòng thứ ba chứa m số nguyên đã được sắp xếp tăng dần (mảng c).
//
// OUTPUT
// In ra một dòng gồm n + m số, mỗi số là "bX" hoặc "cY" với X, Y là chỉ số phần tử (bắt đầu từ 1) của mảng b hoặc c được chọn vào mảng kết quả.
//
// VÍ DỤ
//
// Ví dụ 1
// Input
// 3 4
// 1 3 5
// 2 4 6 7
//
// Output
// b1 c1 b2 c2 b3 c3 c4
//
// Ví dụ 2
// Input
// 2 3
// 2 5
// 1 3 4
//
// Output
// c1 b1 c2 c3 b2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int b[n], c[m];
    for (int& x : b)
        cin >> x;
    for (int& x : c)
        cin >> x;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (b[i] <= c[j]) {
            cout << "b" << i + 1 << " ";
            i++;
        } else {
            cout << "c" << j + 1 << " ";
            j++;
        }
    }
    while (i < n) {
        cout << "b" << i + 1 << " ";
        i++;
    }
    while (j < m) {
        cout << "c" << j + 1 << " ";
        j++;
    }
    return 0;
}
