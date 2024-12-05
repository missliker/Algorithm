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

    int n, a, b, c, d;
    cin >> n >> a >> b >> c;
    vector<int> x(n), y(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cin >> d;
    for (int i = 0; i < n; i++) {
        ans += (x[i] + y[i] < c and min(x[i] + d, a) + y[i] >= c);
    }
    cout << ans << '\n';

    return 0;
}