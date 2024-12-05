#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int x, y;
    cin >> x >> y;
    if (x < 0 or y < 0) {
        cout << "PING\n";
        return;
    }

    if (x == y) {
        cout << "NO\n";
    } else if (abs(x - y) == 1) {
        cout << "YES\n";
    } else {
        cout << "PING\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}