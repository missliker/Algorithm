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

    int n, q;
    cin >> n >> q;
    while (q--) {
        int k, r;
        cin >> k >> r;
        int m = n - r, cnt = 0;
        for (i64 i = 1; i * i <= m; i++) {
            if (m % i == 0) {
                if (i > r) {
                    cnt++;
                }
                if (m / i != i and m / i > r) {
                    cnt++;
                }
            }
        }
        cout << (cnt >= k ? "YES" : "NO") << '\n';
    }

    return 0;
}