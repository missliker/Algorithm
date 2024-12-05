#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i += 1) cin >> x[i] >> y[i];
    auto f = [&](vector<int> x) {
        vector<i64> g(d + 1);
        ranges::sort(x);
        i64 k = -n, b = 0;
        for (i64 xi : x) b += xi;
        for (int x0 = x[0] - d, p = 0; x0 <= x[n - 1] + d; x0 += 1) {
            while (p < n and x[p] <= x0) {
                k += 2;
                b -= x[p] * 2;
                p += 1;
            }
            i64 y = k * x0 + b;
            if (y >= 0 and y <= d) g[y] += 1;
        }
        return g;
    };
    auto fx = f(x), fy = f(y);
    i64 ans = 0;
    for (i64 i = d, sum = 0; i >= 0; i -= 1) {
        sum += fx[d - i];
        ans += sum * fy[i];
    }
    cout << ans;
}