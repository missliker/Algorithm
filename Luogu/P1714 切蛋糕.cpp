#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

template <typename T>
struct ST {
    int n;
    vector<T> vec;
    vector<int> lg;
    vector<vector<T>> info;
    using func_type = function<T(const T&, const T&)>;
    static T default_func(const T& x, const T& y) { return max(x, y); }

    func_type op;
    ST(const vector<T>& v, func_type _func = default_func) { init(v, _func); }

    void init(const vector<T>& in, func_type _func) {
        op = _func;
        vec = in;
        n = vec.size();

        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        info.assign(lg[n] + 1, vector<T>(n));
        for (int i = 0; i < n; i++) {
            info[0][i] = vec[i];
        }

        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 0; j + (1 << i) - 1 < n; j++) {
                info[i][j] = op(info[i - 1][j], info[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T operator()(int l, int r) {
        int k = lg[r - l + 1];
        return op(info[k][l], info[k][r - (1 << k) + 1]);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<i64> s(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    debug(s);

    ST<i64> st(s, [&](i64 x, i64 y) { return min(x, y); });
    for (int i = 1; i <= n; i++) {
        debug(s[i] - st(i - m, i));
        dp[i] = max(dp[i], s[i] - st(max(0, i - m), i));
    }
    debug(dp);

    i64 ans = -1E18;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}