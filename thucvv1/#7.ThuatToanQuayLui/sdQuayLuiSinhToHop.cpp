// ### ĐỀ BÀI: SINH TỔ HỢP CHẬP K CỦA N PHẦN TỬ

// Cho hai số nguyên dương **n** và **k** (1 ≤ k ≤ n ≤ 20).  
// Hãy in ra tất cả các tổ hợp chập `k` của `n` phần tử `{1, 2, ..., n}` theo thứ tự từ điển tăng dần.  

// #### Input  
// - Một dòng gồm hai số nguyên `n` và `k`.  

// #### Output  
// - In ra tất cả các tổ hợp chập `k` của `n`.  
// - Mỗi tổ hợp in trên một dòng, các phần tử cách nhau đúng một khoảng trắng.  

// ---

// #### Ví dụ  

// Input  
// 5 3  

// Output  
// 1 2 3  
// 1 2 4  
// 1 2 5  
// 1 3 4  
// 1 3 5  
// 1 4 5  
// 2 3 4  
// 2 3 5  
// 2 4 5  
// 3 4 5  


#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1001];

void in()
{
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) {
            in();
        } else {
            Try(i + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    Try(1);
    return 0;
}