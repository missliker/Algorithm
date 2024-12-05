#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int curCase) {
    i64 k;
    cin >> k;

    auto pre = [&](i64 x) -> i64 {
        i64 res = x / 4, base = 100;
        while (x >= base) {
            res -= x / base;
            res += x / (base * 4);
            base *= 100;
        }
        return x - res;
    };

    i64 lo = 2024, hi = 2E18;
    while (lo < hi) {
        i64 mi = (lo + hi) / 2;
        if (pre(mi) - pre(2024) >= k) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << hi << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int maxCase = 1;
    cin >> maxCase;
    for (int curCase = 1; curCase <= maxCase; curCase++) {
        Solution(curCase);
    }

    return 0;
}