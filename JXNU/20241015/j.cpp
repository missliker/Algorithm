#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

void Solution(int curCase) {
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int ans = 1E9 + 10;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= min(l + 3, n); r++) {
            int res = s[r] - s[l - 1];
            if (minp[res] != res) {
                ans = min(ans, r - l);
            }
        }
    }
    if (ans == 1E9 + 10) {
        ans = -1;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int maxCase = 1;
    cin >> maxCase;
    sieve(1E6 + 10);
    minp[1] = 1;
    for (int curCase = 1; curCase <= maxCase; curCase++) {
        Solution(curCase);
    }

    return 0;
}