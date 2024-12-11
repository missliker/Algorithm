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
    i64 a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b += x;
    }
    if (a == b) {
        cout << "draw" << '\n';
    } else if (a > b) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }

    return 0;
}