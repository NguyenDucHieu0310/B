#include <bits/stdc++.h>
using namespace std;

// Hỏi: so sánh a[i] và a[j], trả về true nếu a[i] < a[j].
bool ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    string resp;
    cin >> resp; // "YES" nếu a[i] < a[j], ngược lại "NO"
    return resp == "YES";
}

// Merge sort dựa trên so sánh a[i] < a[j]
void merge_sort(vector<int>& p, int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    merge_sort(p, l, m);
    merge_sort(p, m, r);
    vector<int> temp;
    int i = l, j = m;
    while (i < m && j < r) {
        if (ask(p[i], p[j])) {
            temp.push_back(p[i++]);
        } else {
            temp.push_back(p[j++]);
        }
    }
    while (i < m) temp.push_back(p[i++]);
    while (j < r) temp.push_back(p[j++]);
    for (int k = l; k < r; k++) p[k] = temp[k - l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    // Sắp xếp các chỉ số theo giá trị ẩn
    merge_sort(p, 0, n);

    // Kết quả: p[0] có giá trị nhỏ nhất => a[p[0]] = 1, ...
    vector<int> a(n+1);
    for (int rank = 0; rank < n; rank++) {
        a[p[rank]] = rank + 1;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? '\n' : ' ');
    }
    cout.flush();
    return 0;
}
