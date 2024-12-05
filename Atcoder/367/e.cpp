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

    int n, k;
    cin >> n >> k;
    vector<int> x(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (k--) {
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[x[i]];
        }
        swap(a, b);
        debug(a);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}