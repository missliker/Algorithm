#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_ = 0) { init(n_); }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T& v) {
        assert(x != 0);
        for (; x <= n; x += x & -x) {
            a[x] = a[x] + v;
        }
    }

    T sum(int x) {
        assert(x <= n);
        T ans{};
        for (; x; x -= x & -x) {
            ans = ans + a[x];
        }
        return ans;
    }

    T rangeSum(int l, int r) { return sum(r) - sum(l - 1); }

    int select(T s) {
        int p = 0;
        for (int i = (1 << __lg(n)) + 1; i; i >>= 1) {
            if (p + i <= n and a[p + i] <= s) {
                p += i;
                s = s - a[p];
            }
        }
        return p;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> pa(n + 1), pb(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pa[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pb[x] = i;
    }

    debug(pa), debug(pb);

    i64 ans = 0;
    Fenwick<int> b1(n + 2), b2(n + 2);
    for (int l = 1, r = 1; r <= n; r++) {
        b1.add(pa[r], 1), b2.add(pb[r], 1);
        int Add1 = pa[r], Add2 = pb[r];
        debug(Add1, Add2);
        auto ask1 = b1.sum(pa[r]), ask2 = b2.sum(pb[r]);
        debug(r, pa[r], pb[r], ask1, ask2);
        while (l < r and ask1 != ask2) {
            b1.add(pa[l], -1), b2.add(pb[l], -1);
            int Sub1 = pa[l], Sub2 = pb[l];
            debug(Sub1, Sub2);
            ask1 = b1.sum(pa[r]), ask2 = b2.sum(pb[r]);
            debug(r, pa[r], pb[r], ask1, ask2);
            l++;
        }
        debug(l, r);
        ans += r - l + 1;
    }
    cout << ans << '\n';

    return 0;
}