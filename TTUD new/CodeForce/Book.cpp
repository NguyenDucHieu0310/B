#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra xem có thể phân chia sao cho tổng lớn nhất của mỗi phần là tối thiểu là max_pages
bool can_partition(const vector<int>& pages, int k, int max_pages) {
    int scribes = 1;
    int current_sum = 0;

    for (int page : pages) {
        current_sum += page;

        if (current_sum > max_pages) {
            current_sum = page;
            scribes++;

            if (scribes > k) {
                return false;
            }
        }
    }

    return true;
}

// Hàm tìm giải pháp tối ưu
void optimal_assignment(int m, int k, vector<int>& pages) {
    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    int result;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (can_partition(pages, k, mid)) {
            result = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    // Xuất kết quả
    int scribes = k;
    int current_sum = 0;
    int remaining_books = m;

    for (int page : pages) {
        current_sum += page;

        if (current_sum > result || remaining_books == 0) {
            cout << "/ ";
            scribes--;
            current_sum = page;
        }

        cout << page << " ";
        remaining_books--;
    }

    cout << endl;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int m, k;
        cin >> m >> k;

        vector<int> pages(m);
        for (int i = 0; i < m; ++i) {
            cin >> pages[i];
        }

        optimal_assignment(m, k, pages);
    }

    return 0;
}
