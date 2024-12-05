#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

template <class Info, class Tag>
struct LazySegmentTree {
    const int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree(int n) : n(n), info(4 << __lg(n)), tag(4 << __lg(n)) {}
    LazySegmentTree(vector<Info> init) : LazySegmentTree(init.size()) {
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                info[p] += init[l];
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

constexpr i64 INF = 1E18;
int mod;

struct Tag {
    i64 add = 0;
    void apply(Tag t) {
        add = add + t.add;
    }
};

struct Info {
    i64 sum = 0;
    i64 act = 1;

    void apply(Tag t) {
        sum = sum + act * t.add;
    }
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

    int n, m;
    cin >> n >> m;
    LazySegmentTree<Info, Tag> seg(n + 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            int l = max(1, b - c), r = min(n, b + c);
            seg.rangeApply(l, r, {b - })
        }
    }

    return 0;
}