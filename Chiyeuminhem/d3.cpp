#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Giá trị vô cực

// Hàm kiểm tra xem đoạn s[i..j] có phải là lặp của một ký tự
bool isSingleChar(const string& s, int i, int j) {
    for (int k = i + 1; k <= j; ++k) {
        if (s[k] != s[i]) return false;
    }
    return true;
}

// Hàm kiểm tra xem đoạn s[i..j] có thể chia thành k lần lặp của chuỗi con độ dài len
bool isRepeated(const string& s, int i, int j, int len) {
    if ((j - i + 1) % len != 0) return false; // Độ dài phải chia hết
    int k = (j - i + 1) / len; // Số lần lặp
    for (int pos = i + len; pos <= j; pos += len) {
        for (int t = 0; t < len; ++t) {
            if (s[i + t] != s[pos + t]) return false;
        }
    }
    return true;
}

// Hàm tính số chữ số cần để biểu diễn số k
int numDigits(int k) {
    return to_string(k).size(); // Luôn tính số chữ số, kể cả k=1
}

// Hàm DP tính độ dài chuỗi mã hóa ngắn nhất cho đoạn s[i..j]
int solve(const string& s, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0; // Trường hợp rỗng
    if (i == j) return 1; // Một ký tự
    if (dp[i][j] != -1) return dp[i][j]; // Đã tính trước đó
    
    int len = j - i + 1;
    int min_len = len; // Trường hợp cơ bản: giữ nguyên tất cả ký tự
    
    // Trường hợp lặp ký tự đơn
    if (isSingleChar(s, i, j)) {
        min_len = min(min_len, numDigits(len) + 1); // Ví dụ: "aaa" -> "3a"
    }
    
    // Trường hợp chia đoạn
    for (int k = i; k < j; ++k) {
        min_len = min(min_len, solve(s, i, k, dp) + solve(s, k + 1, j, dp));
    }
    
    // Trường hợp lặp chuỗi con
    for (int sub_len = 1; sub_len <= len; ++sub_len) {
        if (isRepeated(s, i, j, sub_len)) {
            int k = len / sub_len; // Số lần lặp
            int sub_cost = solve(s, i, i + sub_len - 1, dp); // Chi phí mã hóa chuỗi con
            int cost = numDigits(k) + 2 + sub_cost; // k(sub): số + 2 ngoặc + chuỗi con
            if (k == 1) cost = sub_cost; // Nếu k=1, không cần số và ngoặc
            min_len = min(min_len, cost);
        }
    }
    
    return dp[i][j] = min_len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    int case_num = 0;
    
    // Đọc input đến khi gặp "0"
    while (cin >> s && s != "0") {
        case_num++;
        int n = s.size();
        
        // Khởi tạo bảng DP
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Tính độ dài chuỗi mã hóa ngắn nhất
        int result = solve(s, 0, n - 1, dp);
        
        // In kết quả
        cout << "Case " << case_num << ": " << result << endl;
    }
    
    return 0;
}