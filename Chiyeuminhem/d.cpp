#include <bits/stdc++.h>
using namespace std;

// Hàm tính số chữ số của một số nguyên
int numDigits(int k) {
    if (k <= 1) return 0; // Nếu k=1, không cần ghi số
    return to_string(k).size(); // Số chữ số của k
}

// Hàm kiểm tra xem đoạn [i..i+len-1] có lặp k lần tới vị trí j không
bool canRepeat(const string& s, int i, int j, int len, int k) {
    if ((j - i + 1) != len * k) return false; // Kiểm tra độ dài
    for (int p = i; p <= j - len; p += len) {
        for (int q = 0; q < len; ++q) {
            if (s[p + q] != s[i + q]) return false; // So sánh ký tự
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    int caseNum = 0;
    
    while (cin >> s && s != "0") {
        caseNum++;
        int n = s.size();
        
        // Khởi tạo mảng DP
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        // Khởi tạo các trường hợp cơ bản: độ dài 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1; // Một ký tự đơn: độ dài mã hóa = 1
        }
        
        // Quy hoạch động lực theo độ dài đoạn
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                
                // Trường hợp 1: Ghi từng ký tự riêng lẻ
                if (len == 1) continue; // Đã khởi tạo
                dp[i][j] = len; // Ghi từng ký tự: độ dài = len
                
                // Trường hợp 2: Kiểm tra lặp ký tự đơn
                bool same = true;
                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] != s[i]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    dp[i][j] = min(dp[i][j], 1 + numDigits(len)); // k + ký tự
                }
                
                // Trường hợp 3: Kiểm tra lặp chuỗi con
                for (int subLen = 1; subLen <= len / 2; ++subLen) {
                    if (len % subLen == 0) { // Độ dài đoạn chia hết cho subLen
                        int k = len / subLen; // Số lần lặp
                        if (canRepeat(s, i, j, subLen, k)) {
                            // Mã hóa: k + ( + mã hóa đoạn subLen + )
                            int cost = numDigits(k) + 2 + dp[i][i + subLen - 1];
                            dp[i][j] = min(dp[i][j], cost);
                        }
                    }
                }
                
                // Trường hợp 4: Chia đoạn thành hai phần
                for (int k = i; k < j; ++k) {
                    if (dp[i][k] != INT_MAX && dp[k + 1][j] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        
        // In kết quả
        cout << "Case " << caseNum << ": " << dp[0][n-1] << endl;
    }
    
    return 0;
}