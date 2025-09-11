// ĐỀ BÀI

// Cho số nguyên dương n.  
// Hãy liệt kê tất cả các hoán vị của dãy {1, 2, ..., n} sao cho trong hoán vị không tồn tại hai số liên tiếp có hiệu tuyệt đối bằng 1.  

// In mỗi hoán vị trên một dòng.

// INPUT  
// - Dòng 1: số nguyên n (1 ≤ n ≤ 10).  

// OUTPUT  
// - Ghi ra tất cả các hoán vị thỏa mãn điều kiện, mỗi hoán vị một dòng.  
// - Các số trong hoán vị được ghi liền nhau, không có khoảng trắng.  

// VÍ DỤ  

// Ví dụ 1  
// Input  
// 3  

// Output  
// 312  
// 132  

// Giải thích: Với n = 3, có 6 hoán vị của {1, 2, 3}:  
// 123, 132, 213, 231, 312, 321.  
// Chỉ có 132 và 312 là thỏa mãn vì không có hai số nào đứng cạnh nhau mà chênh lệch đúng 1.



#include <bits/stdc++.h>
using namespace std;

int n, daXet[1001], X[1001];

bool check(int a[], int l, int r)
{
    for (int i = l; i < r; i++) {
        if (abs(a[i] - a[i + 1]) == 1) {
            return false;
        }
    }
    return true;
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (daXet[j] == 0) {
            X[i] = j;
            daXet[j] = 1;
            if (i == n) {
                bool ok = check(X, 1, n);
                if(ok){
                    for(int i = 1; i <= n; i++){
                        cout << X[i];
                    }
                    cout << endl;
                }
            } else {
                Try(i + 1);
            }
            daXet[j] = 0;
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
    return 0;
}