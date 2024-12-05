#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> ma, mb;
    for (int i = 1; i <= n; i++) {
        cin >> a[n + 1 - i];
        b[a[n + 1 - i]] += 1;
    }
    int ans = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] > 0) {
            ma[i] += 1;
            res += 1;
        }
    }
    int cnt = res;
    for (int i = 1; i <= n; i++) {
        b[a[i]] -= 1;
        if (mb[a[i]] == 0) cnt -= 1;
        mb[a[i]] += 1;
        if (b[a[i]] == 0) {
            ma[a[i]] = 0;
            res -= 1;
        }
        if (cnt == 0) {
            ans += 1;
            mb.clear();
            cnt = res;
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
