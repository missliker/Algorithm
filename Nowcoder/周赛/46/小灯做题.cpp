#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

void Solution(int T) {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    auto mex = [&](int a, int b) {
        for (int i = 0;; i++) {
            if (i != a and i != b) return i;
        }
    };

    int ans = 666;
    auto dfs = [&](auto self, int a, int b, int c, int cnt) -> void {
        if (cnt > 5) return;
        if (a == k or b == k or c == k) {
            ans = min(ans, cnt);
            return;
        }
        self(self, a, b, mex(a, b), cnt + 1);
        self(self, a, mex(a, c), c, cnt + 1);
        self(self, mex(b, c), b, c, cnt + 1);
    };

    dfs(dfs, a, b, c, 0);
    if (ans == 666) ans = -1;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}