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

    int n = Rand<int>(2, 8), k = Rand<int>(1, n);
    cout << n << ' ' << k << '\n';
    auto v = Rand<vector<int>>(n, 1, 100);
    for (auto& x : v) {
        cout << x << ' ';
    }
    cout << '\n';
    int s = Rand<int>(1, n);
    cout << s << '\n';

    return 0;
}