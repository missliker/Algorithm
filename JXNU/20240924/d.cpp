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
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    while (m--) {
        int q;
        cin >> q;
        int ans = ranges::lower_bound(s, q) - begin(s);
        if (ans > n) {
            ans = -1;
        }
        cout << ans << '\n';
    }

    return 0;
}