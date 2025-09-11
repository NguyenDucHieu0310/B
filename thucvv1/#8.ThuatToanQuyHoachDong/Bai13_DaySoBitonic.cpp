// ## Đề bài
// Cho một dãy số nguyên `a[1..n]`. Hãy tìm tổng lớn nhất của một **dãy con tăng giảm (bitonic subsequence)**, nghĩa là dãy con tăng lên rồi giảm xuống.

// ## Input
// - Dòng 1: Số nguyên `n` (1 ≤ n ≤ 10^5)  
// - Dòng 2: n số nguyên a[i] (|a[i]| ≤ 10^9)

// ## Output
// - Một số nguyên duy nhất là tổng lớn nhất của dãy con bitonic.

// ## Ví dụ

// ### Input
// 6  
// 1 15 51 45 33 100  

// ### Output
// 141

// (Giải thích: Dãy con bitonic có tổng lớn nhất là 1 + 15 + 51 + 45 + 33 = 145, sau khi trừ số trung tâm tính trùng lặp sẽ ra 141)



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> S1(n);
    vector<int> S2(n);
    vector<int> kq(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S1[i] = a[i];
        S2[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                S1[i] = max(S1[i], S1[j] + a[i]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j]) {
                S2[i] = max(S2[i], S2[j] + a[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        kq[i] = S1[i] + S2[i] - a[i];
    }
    cout << *max_element(kq.begin(), kq.end()) << endl;
    return 0;
}