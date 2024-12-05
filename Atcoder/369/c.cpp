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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = 0;
    for (int l = 0, r = l + 1; l < n; l++) {
        if (l == n - 1) {
        	ans++;
        	continue;
        }
        int k = a[l + 1] - a[l];
        while (r < n and a[r] - a[r - 1] == k) {
            r++;
        }
        ans += r - l;
        debug(r - l);
    }
    cout << ans << '\n';

    return 0;
}