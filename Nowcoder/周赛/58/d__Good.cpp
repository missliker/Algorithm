#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using d64 = long double;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    i64 n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << 1 << '\n';
        return;
    }

    i64 ans = 0;
    while (n) {
        ans = max(ans, n % k);
        n /= k;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}