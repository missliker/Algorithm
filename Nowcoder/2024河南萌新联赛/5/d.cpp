#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1E5 + 10;
int n, q;
int a[N];

struct Tag {
    int add = 0;
} tag[N << 2];

struct Info {
    i64 sum = 0;
    int act = 1;
} info[N << 2];

Info operator+(Info a, Info b) {
    a.sum += b.sum;
    a.act += b.act;
    return a;
}

Info operator+(Info x, Tag t) {
    x.sum = x.sum + t.add * x.act;
    return x;
}

Tag operator+(Tag a, Tag b) {
    a.add += b.add;
    return a;
}

#define L p << 1
#define R p << 1 | 1

void pull(int p) { info[p] = info[L] + info[R]; }

void apply(int p, Tag t) {
    tag[p] = tag[p] + t;
    info[p] = info[p] + t;
}

void push(int p) {
    if (tag[p].add == 0) return;
    apply(L, tag[p]);
    apply(R, tag[p]);
    tag[p] = Tag();
}

void build(int p = 1, int l = 0, int r = n) {
    if (r - l == 1) {
        info[p] = {a[l], 1};
        tag[p] = {0};
        return;
    }
    int m = (l + r) >> 1;
    build(L, l, m);
    build(R, m, r);
    pull(p);
}

void modify(int p, int l, int r, int x, Info v) {
    if (r - l == 1) {
        info[p] = v;
        return;
    }
    int m = (l + r) >> 1;
    push(p);
    if (x < m) {
        modify(L, l, m, x, v);
    } else {
        modify(R, m, r, x, v);
    }
    pull(p);
}

void modify(int x, Info v) { modify(1, 0, n, x, v); }

void rangeApply(int p, int l, int r, int x, int y, Tag v) {
    if (l >= y or r <= x) {
        return;
    }
    if (l >= x and r <= y) {
        apply(p, v);
        return;
    }
    int m = (l + r) >> 1;
    push(p);
    rangeApply(L, l, m, x, y, v);
    rangeApply(R, m, r, x, y, v);
    pull(p);
}

void rangeApply(int x, int y, Tag v) { rangeApply(1, 0, n, x, y, v); }

Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y or r <= x) {
        return Info();
    }
    if (l >= x and r <= y) {
        return info[p];
    }
    int m = (l + r) >> 1;
    push(p);
    return rangeQuery(L, l, m, x, y) + rangeQuery(R, m, r, x, y);
}

Info rangeQuery(int x, int y) { return rangeQuery(1, 0, n, x, y); }

#undef L
#undef R

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build();

    cin >> q;
    while (q--) {
        int o, x, y, k;
        cin >> o;
        if (o == 1) {
            cin >> x >> y >> k;
            x--;
            rangeApply(x, y, {k});
        } else {
            cin >> x;
            x--;
            cout << rangeQuery(x, x + 1).sum << '\n';
        }
    }

    return 0;
}