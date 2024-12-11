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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    i64 ans = 0, cnt = 0, div = 0, base = 3;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            if (i - 1 and a[i - 1] == 2) {
                ans += 9;
            } else if (i - 2 and a[i - 2] == 2) {
                ans += 9;
            } else {
                ans += 6;
            }
        } else if (a[i] == 3) {
            cnt++;
        } else if (a[i] == 4) {
            div++;
        }
        ans += (base + div * 2) * cnt;
    }
    cout << ans << '\n';

    return 0;
}