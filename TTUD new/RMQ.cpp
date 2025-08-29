#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int BLOCK_SIZE = 700;  // Chọn một giá trị phù hợp với kích thước của dữ liệu

int arr[MAXN];
int minBlock[MAXN / BLOCK_SIZE];

void buildMinBlocks(int n) {
    for (int i = 0; i < n; i++) {
        if (i % BLOCK_SIZE == 0 || arr[i] < minBlock[i / BLOCK_SIZE]) {
            minBlock[i / BLOCK_SIZE] = arr[i];
        }
    }
}

int query(int l, int r) {
    int minVal = INT_MAX;

    while (l % BLOCK_SIZE != 0 && l <= r) {
        minVal = min(minVal, arr[l]);
        l++;
    }

    while (l + BLOCK_SIZE <= r) {
        minVal = min(minVal, minBlock[l / BLOCK_SIZE]);
        l += BLOCK_SIZE;
    }

    while (l <= r) {
        minVal = min(minVal, arr[l]);
        l++;
    }

    return minVal;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMinBlocks(n);

    int m;
    cin >> m;

    int Q = 0;
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        Q += query(i, j);
    }

    cout << Q << endl;

    return 0;
}
