#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n), c(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    for (int& i : c) cin >> i;
    vector<i64> need(n);
    for (int i = 0; i < n; i++) {
        i64 tmp = 1LL * a[i] - 1LL * m * b[i];
        if (tmp > 0) {
            need[i] = 0;
        } else {
            need[i] = (-tmp + c[i]) / c[i];
        }
    }
    ranges::sort(need);
    for (int i = 1; i < n; i++) need[i] += need[i - 1];
    int ans = ranges::upper_bound(need, k) - begin(need);
    cout << ans << '\n';

    return 0;
}