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

    int n = Rand<int>(1, 200), q = Rand<int>(2, 6);
    cout << n << ' ' << q << endl;
    while (q--) {
        int k = Rand<int>(1, 20), r = Rand<int>(0, n - 1);
        cout << k << ' ' << r << endl;
    }

    return 0;
}