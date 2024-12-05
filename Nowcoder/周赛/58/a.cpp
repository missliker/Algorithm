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

    double w;
    i64 h;
    cin >> w >> h;
    w = w * 1000000;
    h = h * 1000000;
    if (h > w) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}