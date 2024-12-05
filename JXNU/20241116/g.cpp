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

    int L, R;
    cin >> L >> R;
    int ans = 0;
    for (int x = L; x <= R; x++) {
        if ((x - 2024) % 4 == 0 or (x - 2022) % 4 == 0) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}