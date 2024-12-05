#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 450000;
const i64 INF = 1e18, mod = 998244353;
i64 a[N];
int n, q;

struct Info {
    int l;
    int r;
    i64 s;
    i64 ors;
} seg[N << 2];

void build(int id = 1, int l = 1, int r = n) {
    seg[id].l = l, seg[id].r = r;
    if (l == r) {
        seg[id].s = a[r] * a[r] % mod;
        seg[id].ors = a[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id].s = (seg[id << 1].s + seg[id << 1 | 1].s) % mod;
    seg[id].ors = seg[id << 1].ors | seg[id << 1 | 1].ors;
}

void rangeApply(int id, int l, int r, int val) {
    if (seg[id].ors == (val & seg[id].ors)) return;
    if (seg[id].l > r or seg[id].r < l) return;
    if (seg[id].l == seg[id].r) {
        seg[id].ors &= val;
        seg[id].s = seg[id].ors * seg[id].ors % mod;
        return;
    }
    rangeApply(id << 1, l, r, val);
    rangeApply(id << 1 | 1, l, r, val);
    seg[id].s = (seg[id << 1].s + seg[id << 1 | 1].s) % mod;
    seg[id].ors = seg[id << 1].ors | seg[id << 1 | 1].ors;
}

void rangeApply(int l, int r, int val) {
    rangeApply(1, l, r, val);
    return;
}

i64 rangeQuery(int id, int l, int r) {
    if (seg[id].l > r or seg[id].r < l) return 0LL;
    if (seg[id].l == l and seg[id].r == r) return seg[id].s;
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (r <= mid) return rangeQuery(id << 1, l, r);
    else if (l > mid) return rangeQuery(id << 1 | 1, l, r);
    return (rangeQuery(id << 1, l, mid) % mod + rangeQuery(id << 1 | 1, mid + 1, r) % mod) % mod;
}

i64 rangeQuery(int l, int r) { return rangeQuery(1, l, r); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    cin >> q;
    while (q--) {
        int o, l, r, x;
        cin >> o;
        if (o == 1) {
            cin >> l >> r >> x;
            rangeApply(l, r, x);
        } else {
            cin >> l >> r;
            cout << rangeQuery(l, r) << '\n';
        }
    }

    return 0;
}