// ### ĐỀ BÀI: BÀI TOÁN CÁI TÚI 0/1 (KNAPSACK)

// Cho một ba lô có sức chứa tối đa **S** và có **n** đồ vật, mỗi đồ vật có trọng lượng `a[i]` (1 ≤ i ≤ n).  
// Hãy chọn một số đồ vật đưa vào ba lô sao cho tổng trọng lượng không vượt quá **S** và là **lớn nhất có thể**.  

// #### Input  
// - Dòng 1: Hai số nguyên `S`, `n` (1 ≤ S ≤ 1000, 1 ≤ n ≤ 1000).  
// - Dòng 2: `n` số nguyên `a[1], a[2], ..., a[n]` (1 ≤ a[i] ≤ S).  

// #### Output  
// - Một số nguyên duy nhất là tổng trọng lượng lớn nhất có thể cho vào ba lô.  

// ---

// #### Ví dụ  

// Input  
// 10 4  
// 6 7 3 4  

// Output  
// 10  


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int s, n;
    cin >> s >> n;
    int dp[n + 2][s + 2];
    int a[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (j < a[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}