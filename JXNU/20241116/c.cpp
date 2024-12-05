#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif
#define __bit(x) (bitset<32>(x))

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    bool ok = false;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] & a[j]) == 0) {
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';

    return 0;
}