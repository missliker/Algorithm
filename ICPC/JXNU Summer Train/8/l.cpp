#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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
};

struct Tag {
    i64 add = 0;
    void apply(Tag t) { add = add + t.add; }
};

struct Info {
    i64 sum = 0;
    int act = 0;
    void apply(Tag t) { sum = sum + t.add * act; }
};

Info operator+(Info a, Info b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.act = a.act + b.act;
    return c;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<Info> init(n + 1);
    for (int i = 1; i <= n; i++) {
        init[i] = {a[i], s[i]};
    }
    LazySegmentTree<Info, Tag> seg(init);

    auto debug = [&]() -> void {
        cout << "debug: " << endl;
        for (int i = 1; i <= n; i++) {
            cout << seg.rangeQuery(i, i).sum << " \n"[i == n];
        }
        for (int i = 1; i <= n; i++) {
            cout << seg.rangeQuery(i, i).act << " \n"[i == n];
        }
    };
    // debug();
    while (q--) {
        int o, x, l, r;
        cin >> o;
        if (o <= 2) {
            cin >> x;
            auto [sum, act] = seg.rangeQuery(x, x);
            seg.modify(x, {sum, 1 - act});
        } else if (o == 3) {
            cin >> l >> r >> x;
            seg.rangeApply(l, r, {x});
        } else {
            cin >> l >> r;
            cout << seg.rangeQuery(l, r).sum << '\n';
        }
        // debug();
    }

    return 0;
}