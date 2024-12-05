#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    i64 l = n / 2, r = n - l;
    i64 ans = l * r;
    cout << ans << '\n';

    return 0;
}