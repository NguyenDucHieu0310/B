#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int merge(vector<int>&a, vector<int>&temp,int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2, i = l, j = mid + 1, k = l, count = 0;
    count += merge(a, temp, l, mid);
    count += merge(a, temp, mid + 1, r);
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            count = (count + (mid - i + 1)) % mod;
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = temp[i];
    return count;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    cout.tie(0);
    int n;cin>>n;
    vector<int> a(n), temp(n);
    for (int i = 0; i <n; i++) cin >> a[i];
    cout << merge(a, temp,0, n-1);
    return 0;
}
