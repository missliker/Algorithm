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
    vector<i64> d(n + 1), t(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
    }

    debug(d);
    debug(t);

    int q;
    cin >> q;
    debug(q);
    while (q--) {
        i64 tim, x;
        cin >> tim >> x;
        i64 sta = max<i64>(tim - d[x], 0LL);
        int i = lower_bound(t.begin() + 1, t.end(), sta) - t.begin();
        debug(i);
        if (i > m) {
            cout << "TNT\n";
            continue;
        }
        cout << t[i] + d[x] - tim << '\n';
    }

    return 0;
}