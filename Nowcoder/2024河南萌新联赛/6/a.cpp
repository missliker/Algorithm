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

    i64 n = 1E16;
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    i64 x = (n * a / 100) * b + n * (100 - a) / 100;
    i64 y = (n * c / 100) * d + n * (100 - c) / 100;
    if (y > x) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}