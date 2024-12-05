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

    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    int ans = 1E9 + 10;
    for (int i = 0; i < (1LL << n); i++) {
        int a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            int x = i >> j & 1;
            x ? a += k[j] : b += k[j];
        }
        ans = min(ans, max(a, b));
    }
    cout << ans << '\n';

    return 0;
}