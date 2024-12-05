#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
constexpr int INF = 1E9 + 10;

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
        if (l > y or r < x or !pred(info[p])) { return -1; }
        if (l == r) { return l; }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) { res = findFirst(2 * p + 1, m + 1, r, x, y, pred); }
        return res;
    }
    template <class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 1, n, l, r, pred);
    }

    template <class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l > y or r < x or !pred(info[p])) { return -1; }
        if (l == r) { return l; }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m + 1, r, x, y, pred);
        if (res == -1) { res = findLast(2 * p, l, m + 1, x, y, pred); }
        return res;
    }
    template <class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 1, n, l, r, pred);
    }
};

struct Tag {
    int add = 0;
    void apply(Tag t) { add = add + t.add; }
};

struct Info {
    i64 c = 0;
};

Info operator+(Info a, Info b) {
    a.c += b.c;
    return a;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(m);
    vector<i64> v(n + 1);
    for (auto& x : p) cin >> x;
    for (int i = 0; i < m; i++) {
        i64 val;
        cin >> val;
        v[p[i]] = val;
    }
    vector<Info> init(n + 1);
    vector<int> L(n + 1, 1), R(n + 1, n);
    set<int> st{p.begin(), p.end()};
    for (int i = 1; i <= n; i++) {
        auto it = st.lower_bound(i);
        if (*it == i) {
            L[i] = i;
            R[i] = i;
            continue;
        }
        R[i] = *it;
        if (it == st.begin()) {
            L[i] = 1;
            continue;
        }
        it--;
        L[i] = *it;
    }
    for (int i = 1; i <= n; i++) {
        if (i == L[i] or i == R[i]) {
            init[i].c = 0;
            continue;
        }
        init[i].c = v[L[i]] * v[R[i]];
    }
    SegmentTree<Info> seg(init);
    // for (int i = 1; i <= n; i++) cerr << L[i] << ' ' << R[i] << '\n';
    // for (int i = 1; i <= n; i++) {
    //     //
    //     cerr << seg.rangeQuery(i, i).c << " \n"[i == n];
    // }
    while (q--) {
        int o, x, val, l, r;
        cin >> o;
        if (o == 1) {
            cin >> x >> val;
            auto it = st.lower_bound(x);
            int r = *it, l;
            if (it == st.begin()) {
                l = 1;
            } else {
                it--;
                l = *it;
            }
            v[x] = val;
            st.insert(x);
            for (int i = l; i <= r; i++) {
                if (i == x) {
                    i64 z = seg.rangeQuery(i, i).c;
                    seg.modify(i, {0});
                    continue;
                }
                if (st.find(i) != st.end()) continue;
                if (i < x) R[i] = x;
                else if (i > x) L[i] = x;
                i64 z = seg.rangeQuery(i, i).c;
                seg.modify(i, {v[L[i]] * v[R[i]]});
            }
        } else {
            cin >> l >> r;
            cout << seg.rangeQuery(l, r).c << '\n';
        }
        // if (o == 1)
        //     for (int i = 1; i <= n; i++) {
        //         //
        //         cerr << seg.rangeQuery(i, i).c << " \n"[i == n];
        //     }
    }

    return 0;
}