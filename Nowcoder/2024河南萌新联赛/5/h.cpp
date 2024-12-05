#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

namespace IO {

char *p1, *p2, buf[1 << 20];
#ifdef missliker
#else
#define getchar() (p1 == p2 and (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
#endif

template <typename T>
T read() {
    T x = 0;
    int f = 1;
    char ch = getchar();
    for (; ch < '0' or ch > '9'; ch = getchar()) {
        if (ch == '-') {
            f = -1;
        }
    }
    for (; ch >= '0' and ch <= '9'; ch = getchar()) {
        x = ((x << 3) + (x << 1)) + (ch - '0');
    }
    return x * f;
}

template <typename T>
void print(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

} // namespace IO

template <class T>
struct RMQ {
    int n;
    vector<T> a;
    vector<array<T, 30>> f;
    function<T(T, T)> func;

    RMQ() {};

    RMQ(vector<T> init_, function<T(T, T)> func_) { work(init_, func_); }

    void work(vector<T>& init_) {
        work(init_, [&](int x, int y) { return max(x, y); });
    }

    void work(vector<T>& init_, function<T(T, T)> func_) {
        this->a = init_;
        this->func = func_;
        this->n = a.size();
        this->f.assign(n, {});
        for (int i = 1; i < n; i++) f[i][0] = a[i];
        for (int j = 1; j <= __lg(n) + 1; j++) {
            for (int i = 1; i + (1 << j) - 1 < n; i++) {
                f[i][j] = func(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int k = log2(r - l + 1);
        return func(f[l][k], f[r - (1 << k) + 1][k]);
    }
};

int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    // cout << fixed << setprecision(20);

    int n = IO::read<int>();
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = IO::read<i64>();
    }

    RMQ<i64> rmq(a, [&](i64 x, i64 y) { return max(x, y); });
    int q = IO::read<int>();
    while (q--) {
        int l = IO::read<int>(), r = IO::read<int>();
        i64 ans = rmq.query(l, r);
        IO::print(ans);
        cout << '\n';
    }

    return 0;
}