#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
typedef pair<i64, i64> PII;
#define x first
#define y second

void solve(int T) {
    i64 n, m;
    cin >> n >> m;
    vector<PII> v(n + 1);
    for (int i = 1; i <= n; i++)  cin >> v[i].x >> v[i].y;
    sort(v.begin() + 1, v.end());
    for (int i = 1; i <= n; i++) v[i].y += v[i - 1].y;
    i64 ans = m;
    for (int i = 1; i <= n; i++) {
        if (v[i].x - v[i].y <= m) {
            ans = max(ans, m + v[i].y);
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}
