#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int i, j, l, r, p;
        cin >> i >> j >> l >> r >> p;
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        int x = 1;
        for (int i = 0; i < n; i++) {
            x &= s[i][j] - '0';
        }
        ans += x;
    }
    cout << ans << '\n';

    return 0;
}