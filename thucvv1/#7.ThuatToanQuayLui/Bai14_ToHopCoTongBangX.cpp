// ĐỀ BÀI  

// Cho dãy số nguyên dương gồm n phần tử và một số nguyên dương S.  
// Hãy tìm tất cả các **tập con** của dãy có tổng đúng bằng S.  

// Nếu không tồn tại tập con nào, in ra -1.  

// INPUT  
// - Dòng 1: hai số nguyên n, S (1 ≤ n ≤ 20, 1 ≤ S ≤ 1000).  
// - Dòng 2: n số nguyên dương a[i] (1 ≤ a[i] ≤ 1000).  

// OUTPUT  
// - Nếu không có tập con nào thỏa mãn, in ra -1.  
// - Nếu có, dòng đầu tiên in số lượng tập con tìm được.  
// - Các dòng tiếp theo, mỗi dòng là một tập con có tổng bằng S, in theo dạng `{x1 x2 ... xk}`.  
// - Các tập con được in theo thứ tự sinh ra khi duyệt tăng dần chỉ số trong dãy (đã được sắp xếp ban đầu).  

// VÍ DỤ  

// Ví dụ 1  
// Input  
// 4 5  
// 1 2 3 4  

// Output  
// 2  
// {1 4}  
// {2 3}  

// Ví dụ 2  
// Input  
// 3 7  
// 2 4 6  

// Output  
// -1  



#include <bits/stdc++.h>
using namespace std;

int n, S, a[1001], X[1001];
vector<vector<int>> res;

void nhap()
{
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

void Try(int i, int pos, int sum)
{
    for (int j = pos; j <= n; j++) {
        if (sum + a[j] <= S) {
            sum += a[j];
            X[i] = a[j];
            if (sum == S) {
                vector<int> tmp(X + 1, X + i + 1);
                res.push_back(tmp);

            } else {
                Try(i + 1, j, sum);
            }
            sum -= a[j];
        }
    }
}

int main()
{
    nhap();
    Try(1, 1, 0);
    if (res.size() == 0) {
        cout << "-1" << endl;
    } else {
        cout << res.size() << endl;
        for (auto it : res) {
            cout << "{";
            for (int j = 0; j < it.size(); j++) {
                cout << it[j];
                if (j == it.size() - 1) {
                    cout << "}" << endl;
                } else {
                    cout << " ";
                }
            }
        }
    }
    return 0;
}