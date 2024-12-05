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

    int n, m;
    cin >> n >> m;
    if (n % 2 == 0 and m % 2 == 0) {
        cout << 1 << ' ' << 1 << '\n';
        for (int i = n; i > 1; i--) {
            cout << i << ' ' << 2 << '\n';
            cout << i << ' ' << 1 << '\n';
        }
        cout << 1 << ' ' << 2 << '\n';
        cout << n << ' ' << 3 << '\n';
        for (int i = 1; i < n; i++) {
            cout << i << ' ' << 4 << '\n';
            cout << i << ' ' << 3 << '\n';
        }
        cout << n << ' ' << 4 << '\n';
        cout << 1 << ' ' << 5 << '\n';
        for (int i = n; i > 1; i--) {
            cout << i << ' ' << 6 << '\n';
            cout << i << ' ' << 5 << '\n';
        }
    }

    return 0;
}