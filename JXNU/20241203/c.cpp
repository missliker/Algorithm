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
    vector<i64> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    i64 ans = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
    	if (r[i - 1] + 1 < l[i]) {
    		ok = false;
    		break;
    	}
        if (ans + 1 >= l[i] and ans + 1 <= r[i]) {
            ans++;
            continue;
        } else if (ans < l[i]) {
            ans = l[i];
        } else {
            ok = false;
            break;
        }
    }
    ans++;
    if (not ok) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}