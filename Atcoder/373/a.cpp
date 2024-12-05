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

    int n = 12, ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() == i + 1) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}