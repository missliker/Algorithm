#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, m, k;
    cin >> n >> m >> k;
    vector s(n + 2, vector<i64>(m + 2, 0LL));
    int w;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<i64>());

    auto insert = [&](int x1, int y1, int x2, int y2, int c) -> void {
        s[x1][y1] += c;
        s[x2 + 1][y1] -= c;
        s[x1][y2 + 1] -= c;
        s[x2 + 1][y2 + 1] += c;
    };

    for (int i = 1; i + k - 1 <= n; i++) {
        for (int j = 1; j + k - 1 <= m; j++) {
            insert(i, j, i + k - 1, j + k - 1, 1);
        }
    }

    vector<int> cnt(k * k + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            cnt[s[i][j]]++;
        }
    }

    i64 ans = 0;
    for (int i = k * k, j = 0; i >= 0; i--) {
        if (not cnt[i]) continue;
        while (cnt[i] and j < w) {
            ans += 1LL * a[j] * i;
            j++;
            cnt[i]--;
        }
        if (j == w) break;
    }
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