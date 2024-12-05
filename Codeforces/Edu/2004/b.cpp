#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    int ans = min(r, R) - max(l, L);
    if (ans < 0) {
        cout << 1 << '\n';
        return;
    }

    ans += (l != L) + (r != R);
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