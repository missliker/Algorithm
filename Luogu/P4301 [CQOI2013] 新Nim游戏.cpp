#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

struct Basis {
    i64 w[63] = {};
    int m = 0;

    void assign() {
        for (int i = 0; i < m; i++) {
            w[i] = 0;
        }
        m = 0;
    }

    i64 insert(i64 x) {
        i64 res = x;
        for (int i = 62; i >= 0; i--) {
            if (x >> i & 1) {
                if (not w[i]) {
                    w[i] = x;
                    if (i + 1 > m) {
                        m = i + 1;
                    }
                    break;
                }
                x ^= w[i];
            }
        }
        if (not x) {
            return res;
        }
        return 0;
    }

    i64 max() {
        i64 res = 0;
        for (int i = m; i >= 0; i--) {
            if ((res ^ w[i]) > res) {
                res ^= w[i];
            }
        }
        return res;
    }

    i64 min() { return w[0]; }

    int size() { return m; }
} basis;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater());

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += basis.insert(a[i]);
    }
    cout << ans << '\n';

    return 0;
}