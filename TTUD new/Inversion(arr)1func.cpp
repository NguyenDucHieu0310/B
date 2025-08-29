#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int n, temp[N], a[N];

int mergeHelper(int l, int r, int mid) {
    int count = 0;
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            count = (count + (mid - i + 1)) % mod; // Increment the count
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = temp[i];
    return count; // Return the count
}

int merge(int l, int r) {
    int count = 0;
    int mid = (l + r) / 2;
    if (l < r) {
        count = (count + merge(l, mid) + merge(mid + 1, r) + mergeHelper(l, r, mid)) % mod; // Return the count
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int result = merge(1, n);
    cout << result;

    return 0;
}
