#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    i64 ans = 0, can = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            ans -= a[i];
            can += a[i - 1] - a[i];
        } else {
            ans += a[i];
        }
    }
    cout << max<i64>(ans - min<i64>(k, can), 0LL) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}