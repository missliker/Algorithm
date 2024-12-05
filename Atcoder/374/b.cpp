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

    string s, t;
    cin >> s >> t;
    for (int i = 0; i < min(s.size(), t.size()); i++) {
        if (s[i] != t[i]) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    if (s.size() == t.size()) {
        cout << 0 << '\n';
    } else {
        cout << min(s.size(), t.size()) + 1 << '\n';
    }

    return 0;
}