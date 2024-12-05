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
    int mid = 0, mid_odd = 0, mid_one = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 and i < n - 1) {
            ans += (a[i] + 1) / 2;
            if (a[i]) {
                mid++;
                if (a[i] == 1) {
                    mid_one++;
                }
            }
            mid_odd += (a[i] & 1);
        }
    }
    if (mid_odd == 1 and mid == 1) {
        cout << "-1\n";
        return 0;
    }
    if (mid == mid_one) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';

    return 0;
}