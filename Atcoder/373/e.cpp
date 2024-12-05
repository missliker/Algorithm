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

    int n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n);
    i64 s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    auto b = a;
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        auto check = [&](i64 x) {
            auto p = ranges::upper_bound(b, x);
            int i = p - begin(b);
            int cnt = end(b) - p;
            i64 have = k - s - x;
            for (int j = i - 1; j >= 0; j--) {
            	if (have >= x + 1 - b[j]) {
            		have -= x + 1 - b[j];
            		cnt++;
            		if (cnt >= m) {
            			return false;
            		}
            	} else {
            		break;
            	}
            }
            return cnt < m;
        };
        i64 lo = 0, hi = k - s + 1;
        while (lo < hi) {
            i64 mi = (lo + hi) / 2;
            if (check(mi + a[i])) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        if (hi > k - s) {
        	hi = -1;
        }
        cout << hi << " \n"[i == n - 1];
    }

    return 0;
}