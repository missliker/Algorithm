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

    int ans = 0, bg = 0;
    for (int i = bg; i < n;) {
        bool jump = false;
        for (int j = i + 1; j < n; j++) {
            if (a[j] >= a[i]) {
                i = j;
                bg = i + 1;
                debug(i);
                if (i != n - 1) ans++;
                jump = true;
                break;
            }
        }
        if (not jump) {
            i++;
        }
    }
    cout << ans << '\n';

    return 0;
}