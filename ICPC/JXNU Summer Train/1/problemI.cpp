#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
+++
++-
+-+
+--
-++
-+-
--+
---
*/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    auto go = [&](i64 f) {
        if (f == 0) return -1;
        return 1;
    };

    i64 ans = 0;
    for (int k = 0; k < (1 << 3); k++) {
        i64 tmp = 0;
        i64 fc = k & 1, fb = k >> 1 & 1, fa = k >> 2 & 1;
        fa = go(fa), fb = go(fb), fc = go(fc);
        for (int i = 0; i < n; i++) {
            i64 s = fa * a[i] + fb * b[i] + fc * c[i];
            if (s >= 0) tmp += s;
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';

    return 0;
}