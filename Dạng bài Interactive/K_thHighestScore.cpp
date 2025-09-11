
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Hàm hỏi điểm số cao thứ i của quốc gia country ("F" hoặc "S")
ll query(const string& country, int i) {
    cout << country << " " << i << endl;
    cout.flush();
    ll score;
    cin >> score;
    return score;
}

// Hàm đếm số điểm lớn hơn hoặc bằng x từ cả hai quốc gia
ll count_scores(ll x, int n) {
    ll count = 0;
    // Đếm từ Phần Lan
    for (int i = 1; i <= n; i++) {
        ll score = query("F", i);
        if (score < x) break; // Điểm nhỏ hơn x, không cần hỏi tiếp
        count++;
    }
    // Đếm từ Thụy Điển
    for (int i = 1; i <= n; i++) {
        ll score = query("S", i);
        if (score < x) break; // Điểm nhỏ hơn x, không cần hỏi tiếp
        count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    // Tìm kiếm nhị phân trên giá trị điểm số
    ll left = 1, right = 1e9;
    ll result = -1;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll count = count_scores(mid, n);
        
        if (count >= k) {
            // Có ít nhất k điểm số >= mid, điểm số cao thứ k có thể là mid hoặc lớn hơn
            result = mid;
            left = mid + 1;
        } else {
            // Có ít hơn k điểm số >= mid, điểm số cao thứ k nhỏ hơn mid
            right = mid - 1;
        }
    }
    
    // In kết quả
    cout << "! " << result << endl;
    cout.flush();
    
    return 0;
}

// Mô tả bài toán

// Có n lập trình viên đến từ Phần Lan và n lập trình viên đến từ Thụy Điển tham gia một cuộc thi lập trình. Sau khi cuộc thi kết thúc, người ta biết rằng mỗi lập trình viên có điểm số khác nhau.

// Nhiệm vụ của bạn là tìm điểm số cao thứ k trong toàn bộ cuộc thi (gồm 2n lập trình viên).

// Tương tác

// Đây là một bài toán tương tác, nghĩa là chương trình của bạn sẽ giao tiếp trực tiếp với hệ thống chấm.

// Bạn có thể đặt câu hỏi để truy vấn điểm số:

// "F i": Hỏi điểm cao thứ i của đội Phần Lan (1 ≤ i ≤ n)

// "S i": Hỏi điểm cao thứ i của đội Thụy Điển (1 ≤ i ≤ n)

// "! s": Báo rằng điểm cao thứ k là s và kết thúc chương trình

// Sau mỗi dòng in ra, bạn cần flush output ngay lập tức để đảm bảo hệ thống chấm nhận được.

// Giới hạn

// 1 ≤ n ≤ 10^5

// 1 ≤ k ≤ 2n

// Mỗi điểm số là một số nguyên trong khoảng [1, 10^9]

// Bạn chỉ được hỏi tối đa 100 câu hỏi (F i hoặc S i)

// Ví dụ

// Input:

// 3 1
// F 1
// 9
// S 1
// 8
// ! 9


// Giải thích:

// Điểm số đội Phần Lan: [9, 4, 3]
// Điểm số đội Thụy Điển: [8, 6, 1]

// Bạn cần tìm điểm cao nhất (k = 1), và đó là 9.







// Mô tả bài toán

// Có n lập trình viên đến từ Phần Lan và n lập trình viên đến từ Thụy Điển tham gia một cuộc thi lập trình. Sau khi cuộc thi kết thúc, người ta biết rằng mỗi lập trình viên có điểm số khác nhau.

// Nhiệm vụ của bạn là tìm điểm số cao thứ k trong toàn bộ cuộc thi (gồm 2n lập trình viên).

// Tương tác

// Đây là một bài toán tương tác, nghĩa là chương trình của bạn sẽ giao tiếp trực tiếp với hệ thống chấm.

// Bạn có thể đặt câu hỏi để truy vấn điểm số:

// "F i": Hỏi điểm cao thứ i của đội Phần Lan (1 ≤ i ≤ n)

// "S i": Hỏi điểm cao thứ i của đội Thụy Điển (1 ≤ i ≤ n)

// "! s": Báo rằng điểm cao thứ k là s và kết thúc chương trình

// Sau mỗi dòng in ra, bạn cần flush output ngay lập tức để đảm bảo hệ thống chấm nhận được.

// Giới hạn

// 1 ≤ n ≤ 10^5

// 1 ≤ k ≤ 2n

// Mỗi điểm số là một số nguyên trong khoảng [1, 10^9]

// Bạn chỉ được hỏi tối đa 100 câu hỏi (F i hoặc S i)

// Ví dụ

// Input:

// 3 1
// F 1
// 9
// S 1
// 8
// ! 9


// Giải thích:

// Điểm số đội Phần Lan: [9, 4, 3]
// Điểm số đội Thụy Điển: [8, 6, 1]

// Bạn cần tìm điểm cao nhất (k = 1), và đó là 9.