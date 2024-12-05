#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        b[i] = n + i;
    }
    for (int i = m; i <= k; i += m) {
        int j = i % n;
        if (i % n == 0) j = n;
        swap(a[j], b[j]);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    for (int i = 1; i <= n; i++) cout << b[i] << ' ';

    return 0;
}