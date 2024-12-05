#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
    template <class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) { init(vector(n_, v_)); }

    template <class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                info[p] = init_[l];
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

    void modify(int p, int l, int r, int x, const Info& v) {
        if (l == r) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m + 1, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info& v) { modify(1, 1, n, p, v); }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y or r < x) return Info();
        if (l >= x and r <= y) return info[p];
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m + 1, r, x, y);
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 1, n, l, r); }

    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l > y or r < x or !pred(info[p])) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m + 1, r, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 1, n, l, r, pred);
    }

    template <class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l > y or r < x or !pred(info[p])) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m + 1, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m + 1, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 1, n, l, r, pred);
    }
};

struct Info {
    int ans = 0;
    int preans = 0;
    int sufans = 0;
    int size = 1;
};

Info operator+(Info a, Info b) {
    Info c;
    c.ans = max({a.ans, b.ans, a.sufans + b.preans});
    c.preans = (a.preans == a.size ? a.size + b.preans : a.preans);
    c.sufans = (b.sufans == b.size ? b.size + a.sufans : b.sufans);
    c.size = a.size + b.size;
    return c;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, q;
    cin >> n >> q;
    SegmentTree<Info> seg(n + 1);
    for (int i = 1; i <= n; i++) {
        seg.modify(i, {1, 1, 1, 1});
    }

    while (q--) {
        int op, x, l, r;
        cin >> op;
        if (op == 1) {
            cin >> x;
            auto t = seg.rangeQuery(x, x);
            if (t.ans == 0) {
                seg.modify(x, {1, 1, 1, 1});
            } else {
                seg.modify(x, {0, 0, 0, 1});
            }
        } else {
            cin >> l >> r;
            cout << seg.rangeQuery(l, r).ans << '\n';
        }
    }

    return 0;
}