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

    if (n == 1) {
        if (a[0] < k) {
            cout << k << '\n';
        } else {
            cout << k - 1 << '\n';
        }
        return;
    }

    int g = 0;
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
    }

    set<i64> st;
    for (int i = 0; i < n; i++) {
        st.insert(1LL * i * g);
    }

    for (int i = 0, j = 0;; i++) {
        if (st.find(i) != st.end()) {
            continue;
        }
        j++;
        if (j == k) {
            cout << i << '\n';
            return;
        }
        if (n > k and j == n) {
            cout << j + k - 1 << '\n';
            return;
        }
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