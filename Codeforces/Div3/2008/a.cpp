#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0 and b % 2 == 0) {
        cout << "YES\n";
        return;
    }

    if (a % 2 == 1 and b % 2 == 1) {
        cout << "NO\n";
        return;
    }

    if (a % 2 == 0) {
        if (a >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
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