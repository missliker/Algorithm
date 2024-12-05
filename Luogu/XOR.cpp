#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

struct Basis {
    i64 w[63] = {};
    int m = 0;

    void assign() {
        for (int i = 0; i < m; i++) {
            w[i] = 0;
        }
        m = 0;
    }

    void insert(i64 x) {
        for (int i = 62; i >= 0; i--) {
            if (x >> i & 1) {
                if (not w[i]) {
                    w[i] = x;
                    if (i + 1 > m) {
                        m = i + 1;
                    }
                    break;
                }
                x ^= w[i];
            }
        }
    }

    void remake(int n) {
        m = 0;
        for (int i = 62; i >= 0; i--) {
            for (int j = m; j < n; j++) {
                if (w[j] >> i & 1) {
                    swap(w[j], w[m]);
                    break;
                }
            }
            if ((w[m] >> i & 1) == 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (j != m and (w[j] >> i & 1)) {
                    w[j] ^= w[m];
                }
            }
            m++;
            if (m == n) {
                break;
            }
        }
        sort(w, w + m);
    }

    i64 max() {
        i64 res = 0;
        for (int i = m - 1; i >= 0; i--) {
            if ((res ^ w[i]) > res) {
                res ^= w[i];
            }
        }
        return res;
    }

    i64 min() { return w[0]; }

    i64 Kth_min(int k, int n) {
        if (m < n) {
            k--;
        }
        if (k >= (1LL << m)) {
            return -1;
        }
        i64 res = 0;
        for (int i = 0; i < m; i++) {
            if (k >> i & 1) {
                res ^= w[i];
            }
        }
        return res;
    }

    int size() { return m; }
} basis;

void Solution(int T) {
    cout << "Case #" << T << ":\n";
    basis.assign();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        basis.insert(a[i]);
    }

    int q;
    cin >> q;
    basis.remake(basis.size());
    while (q--) {
        int k;
        cin >> k;
        cout << basis.Kth_min(k, n) << '\n';
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