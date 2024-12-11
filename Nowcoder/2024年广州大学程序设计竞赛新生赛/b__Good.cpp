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
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == r) {
                cnt++;
            }
        }
        cout << (cnt >= k ? "YES" : "NO") << '\n';
    }

    return 0;
}