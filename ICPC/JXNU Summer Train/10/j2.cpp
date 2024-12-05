#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1 << 20;

constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};
int o[N];
Z s[N];

void pull(int p) {
    o[p] = o[2 * p] | o[2 * p + 1];
    s[p] = s[2 * p] + s[2 * p + 1];
}

void build(int p, int l, int r, auto &a) {
    if (r - l == 1) {
        o[p] = a[l];
        s[p] = Z(a[l]) * a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m, a);
    build(2 * p + 1, m, r, a);
    pull(p);
}

void modify(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x || !(o[p] & ~v)) return;
    if (r - l == 1) {
        o[p] &= v;
        s[p] = Z(o[p]) * o[p];
        return;
    }
    int m = (l + r) / 2;
    modify(2 * p, l, m, x, y, v);
    modify(2 * p + 1, m, r, x, y, v);
    pull(p);
}

Z query(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) return 0;
    if (l >= x && r <= y) return s[p];
    int m = (l + r) / 2;
    return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    build(1, 0, n, a);

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int o;
        std::cin >> o;

        if (o == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--;
            modify(1, 0, n, l, r, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            l--;
            std::cout << query(1, 0, n, l, r) << "\n";
        }
    }

    return 0;
}