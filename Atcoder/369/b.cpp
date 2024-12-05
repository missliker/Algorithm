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
    int ans = 0;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        int a;
        char s;
        cin >> a >> s;
        if (s == 'L') {
            if (l == -1) {
                l = a;
                continue;
            }
            ans += abs(l - a);
            l = a;
        } else {
            if (r == -1) {
                r = a;
                continue;
            }
            ans += abs(r - a);
            r = a;
        }
    }
    cout << ans << '\n';

    return 0;
}