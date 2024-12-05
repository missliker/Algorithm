#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
ostream& operator<<(ostream& os, Pair n) {
    string a, b, s, flag;
    if (n.first < 0) flag = "-", n.first *= -1;
    while (n.first) {
        a += '0' + n.first % 10;
        n.first /= 10;
    }
    a += flag;
    reverse(a.begin(), a.end());
    flag = string("");
    if (n.second < 0) flag = "-", n.second *= -1;
    while (n.second) {
        b += '0' + n.second % 10;
        n.second /= 10;
    }
    b += flag;
    reverse(b.begin(), b.end());
    s = "[" + a + ", " + b + "]\n";
    return os << s;
}

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_ = 0) { init(n_); }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T& v) {
        assert(x != 0);
        for (; x <= n; x += x & -x) a[x] = a[x] + v;
    }

    T sum(int x) {
        assert(x <= n);
        T ans{};
        for (; x; x -= x & -x) ans = ans + a[x];
        return ans;
    }

    T rangeSum(int l, int r) { return sum(r) - sum(l - 1); }

    int select(T s) {
        int p = 0;
        for (int i = (1 << __lg(n)) + 1; i; i >>= 1) {
            if (p + i <= n and a[p + i] <= s) {
                p += i;
                s = s - a[p];
            }
        }
        return p;
    }
};

#define deg(a) cout << #a << " == " << a << ' ';
#define bug(a) cout << #a << " == " << a << endl;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, T;
    string S;
    cin >> N >> T >> S;
    vector<Pair> X(N);
    for (int i = 0; i < N; i++) cin >> X[i].first, X[i].second = S[i] - '0';
    ranges::sort(X);
    vector<i64> P;
    for (int i = 0; i < N; i++) {
        P.push_back(X[i].first);
        if (X[i].second == 0) P.push_back(X[i].first - T);
        else P.push_back(X[i].first + T);
    }
    ranges::sort(P);
    P.erase(unique(P.begin(), P.end()), P.end());

    // for (auto& x : P) cerr << x << ' ';
    // cerr << endl;

    Fenwick<int> L(N * 4), R(N * 4);
    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        // deg(X[i].first);
        // bug(X[i].second);
        if (X[i].second == 0) {
            int l = lower_bound(P.begin(), P.end(), X[i].first - 2 * T) - P.begin() + 1;
            int r = lower_bound(P.begin(), P.end(), X[i].first) - P.begin() + 1;
            i64 cnt = R.rangeSum(l, r);
            ans += cnt;
            // deg(l);
            // bug(r);
            // bug(cnt);
            int p = lower_bound(P.begin(), P.end(), X[i].first) - P.begin() + 1;
            L.add(p, 1);
        } else {
            int l = lower_bound(P.begin(), P.end(), X[i].first) - P.begin() + 1;
            int r = lower_bound(P.begin(), P.end(), X[i].first + 2 * T) - P.begin() + 1;
            i64 cnt = L.rangeSum(l, r);
            ans += cnt;
            // deg(l);
            // bug(r);
            // bug(cnt);
            int p = lower_bound(P.begin(), P.end(), X[i].first) - P.begin() + 1;
            R.add(p, 1);
        }
    }
    cout << ans << '\n';

    return 0;
}