#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    string ans = "buaa-noob";
    map<int, long double> st;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        int v = max(abs(x), abs(y));
        st[v] += 1;
    }
    long double e = 0;
    for (auto [x, y] : st) e += 1.0 * x * y / n;
    if (fabs(e - 66) <= 10) ans = "bit-noob";
    cout << ans;
    return 0;
}
