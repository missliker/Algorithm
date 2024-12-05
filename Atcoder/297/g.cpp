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

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // vector<int> f(100000, -1);
    // auto sg = [&](auto self, int x) -> int {
    //     if (f[x] != -1) {
    //         return f[x];
    //     }

    //     set<int> s;
    //     for (int i = max(0, x - r); i <= min(0, x - l); i++) {
    //         s.insert(self(self, i));
    //     }

    //     for (int i = 0;; i++) {
    //         if (not s.count(i)) {
    //             return f[x] = i;
    //         }
    //     }
    // };

    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     ans ^= sg(sg, a[i]);
    // }

    int ans = 0;

    auto sg = [&](int x) {
        return (x % (l + r)) / l;
    };

    for (int i = 0; i < n; i++) {
        ans ^= sg(a[i]);
    }
    cout << (ans ? "First" : "Second") << '\n';

    return 0;
}