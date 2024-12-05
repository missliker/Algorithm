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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, now = 0;
    while (now < n - 1) {
        int mx = -1;
        int nxt = now;
        for (int i = now + 1; i < n; i++) {
            if (a[i] > mx) {
                mx = a[i];
                nxt = i;
            }
        }
        now = nxt;
        ans++;
    }
    cout << max(ans - 1, 0) << '\n';

    return 0;
}