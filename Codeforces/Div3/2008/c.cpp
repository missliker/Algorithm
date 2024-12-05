#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    i64 l, r;
    cin >> l >> r;
    int lo = 0, hi = r;
    while (lo < hi) {
        int mi = (lo + hi + 1) >> 1;
        if (l + (1LL + mi) * mi / 2LL <= r) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    cout << hi + 1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}