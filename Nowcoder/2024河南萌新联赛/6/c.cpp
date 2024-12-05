#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
        if (w[i] % 16 != 0) {
            w[i] %= 16;
        } else {
            w[i] = 16;
        }
    }
    vector f(m + 1, vector<int>(17));
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            for (int k = 16; k >= 0; k--) {
                f[j][k] = max(f[j][k], f[j - v[i]][(k - w[i] + 16) % 16] + ((k - w[i] + 16) % 16 == 0 or f[j - v[i]][(k - w[i] + 16) % 16] != 0));
            }
        }
    }
    int ans = 0;
    for (int j = m; j >= 0; j--) {
        ans = max({ans, f[j][16], f[j][0]});
    }
    cout << ans << '\n';

    return 0;
}