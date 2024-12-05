#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

template <class Info, class Tag>
struct LazySegmentTree {
    const int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree(int n) : n(n), info(4 << __lg(n)), tag(4 << __lg(n)) {}
    LazySegmentTree(vector<Info> init) : LazySegmentTree(init.size()) {
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 1, n);
    }

    void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }

    void apply(int p, const Tag& v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (l == r) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x <= m) modify(2 * p, l, m, x, v);
        else modify(2 * p + 1, m + 1, r, x, v);
        pull(p);
    }
    void modify(int p, const Info& v) { modify(1, 1, n, p, v); }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y or r < x) return Info();
        if (l >= x and r <= y) return info[p];
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m + 1, r, x, y);
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 1, n, l, r); }

    void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
        if (l > y or r < x) return;
        if (l >= x and r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag& v) { return rangeApply(1, 1, n, l, r, v); }

    void half(int p, int l, int r) {
        if (info[p].act == 0) return;
        if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
            apply(p, {-(info[p].min + 1) / 2});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        half(2 * p, l, m);
        half(2 * p + 1, m + 1, r);
        pull(p);
    }
    void half() { half(1, 1, n); }
};

struct Tag {
    i64 add = 0;
    void apply(Tag t) { add = add + t.add; }
};

struct Info {
    int x;
    int act;
    void apply(Tag t) { x = x + act * t.add; }
};

Info operator+(Info a, Info b) {
    a.x += b.x;
    return a;
}

struct Basis {
    i64 w[63] = {};
    int m = 0;

    void assign() {
        for (int i = 0; i < m; i++) {
            w[i] = 0;
        }
        m = 0;
    }

    bool insert(i64 x) {
        for (int i = 62; i >= 0; i--) {
            if (x >> i & 1) {
                if (not w[i]) {
                    w[i] = x;
                    if (i + 1 > m) {
                        m = i + 1;
                    }
                    return true;
                }
                x ^= w[i];
            }
        }
        return false;
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
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    LazySegmentTree<Info, Tag> seg(n + 1);
    for (int i = 1; i <= n; i++) {
        seg.modify(i, {a[i], 1});
    }

    while (q--) {
        int o, l, r, x;
        cin >> o;
        if (o == 1) {
            cin >> l >> r >> x;
            seg.rangeApply(l, r, {x});
        } else {
            cin >> l >> r;
            Basis basis;
            bool ok = false;
            for (int i = l; i <= r; i++) {
                int x = seg.rangeQuery(i, i).x;
                if (not basis.insert(x)) {
                    ok = true;
                    break;
                }
            }
            cout << (ok ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}