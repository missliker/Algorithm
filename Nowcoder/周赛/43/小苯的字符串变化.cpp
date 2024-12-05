#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<i64> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++) { pre[i] = pre[i - 1] + (s[i] >= 'a' and s[i] <= 'z'); }
    for (int i = n; i >= 1; i--) { suf[i] = suf[i + 1] + (s[i] >= 'A' and s[i] <= 'Z'); }
    i64 ans = 1E18;
    for (int i = 1; i < n; i++) { ans = min(ans, pre[i] + suf[i + 1]); }
    cout << ans << '\n';

    return 0;
}