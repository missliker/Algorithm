#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int n;
    cin >> n;
    vector<i64> v(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin() + 1, v.end());
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + min(2 * v[i], 4 * v[1]);
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
        ans += s[i - 1] + (n - i) * min(4 * v[1], 2 * v[i]);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}
