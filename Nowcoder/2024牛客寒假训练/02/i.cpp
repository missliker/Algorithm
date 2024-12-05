#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int n;
    cin >> n;
    vector<i64> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin() + 1, v.end());
    i64 ans = 0;
    for (int i = 1; i <= n; i++) ans += (i - 1) * v[i];
    ans = ans * 4;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}
