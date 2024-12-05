#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

const i64 mask = 1LL << 18;
int f[(1 << 20) + 1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]--;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (i64 j = i, s = 0; j <= n; j++) {
            if (s >> a[j] & 1) {
                break;
            }
            s |= 1LL << a[j];
            f[s] = max<i64>(f[s], j - i + 1);
            ans = max(ans, f[s]);
        }
    }
    for (i64 i = 0; i < mask; i++) {
        for (i64 j = i; j > 0; j = i & j - 1) {
            ans = max(f[j] + f[i ^ j], ans);
        }
    }
    cout << ans << endl;

    return 0;
}