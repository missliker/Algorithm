#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
#define ll long long
int n, q;
ll x, cnt;
struct Linear_basis {
    ll d[61], p[61];
    void init() {
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
        cnt = 0;
    }
    bool add(ll val) {
        for (int i = 60; i >= 0; i--)
            if (val & (1LL << i)) {
                if (!d[i]) {
                    d[i] = val;
                    break;
                }
                val ^= d[i];
            }
        return val > 0;
    }
    ll query_max() {
        ll ret = 0;
        for (int i = 60; i >= 0; i--)
            if ((ret ^ d[i]) > ret) ret ^= d[i];
        return ret;
    }
    ll query_min() {
        for (int i = 0; i <= 60; i++)
            if (d[i]) return d[i];
        return 0;
    }
    void rebuild() {
        for (int i = 60; i >= 0; i--)
            for (int j = i - 1; j >= 0; j--)
                if (d[i] & (1LL << j)) d[i] ^= d[j];
        for (int i = 0; i <= 60; i++)
            if (d[i]) p[cnt++] = d[i];
    }
    ll kth_query(ll k) {
        int ret = 0;
        if (k >= (1LL << cnt)) return -1;
        for (int i = 60; i >= 0; i--)
            if (k & (1LL << i)) ret ^= p[i];
        return ret;
    }
} LB;
int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d:\n", cas++);
        LB.init();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld", &x), LB.add(x);
        LB.rebuild();
        scanf("%d", &q);
        while (q--) {
            scanf("%lld", &x);
            if (cnt != n) x--;
            printf("%lld\n", LB.kth_query(x));
        }
    }
}