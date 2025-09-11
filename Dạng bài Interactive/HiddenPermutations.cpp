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


// There is a hidden permutation a_1, a_2,\dots, a_n of integers 1, 2,\dots, n. Your task is to find this permutation.
// To do this, you can ask questions: you can choose two indices i and j and you will be told if a_i < a_j.
// Interaction
// This is an interactive problem. Your code will interact with the grader using standard input and output. You should start by reading a single integer n: the length of the permutation.
// On your turn, you can print one of the following:

// "?\ i\ j", where 1 \le i, j \le n: ask if a_i < a_j. The grader will return YES if a_i < a_j and NO otherwise.
// "!\ a_1\ a_2 \dots a_n": report that the hidden permutation is a_1, a_2,\dots, a_n. Your program must terminate after this.

// Each line should be followed by a line break. You must make sure the output gets flushed after printing each line.
// Constraints

// 1 \le n \le 1000
// you can ask at most 10^4 questions of type ?

// Example3
// ? 3 2
// NO
// ? 3 1
// YES
// ! 3 1 2

// Explanation: The hidden permutation is [3, 1, 2]. The first question asks if a_3 < a_2 which is false, so the answer is NO. The second question asks if a_3 < a_1 which is true, so the answer is YES.