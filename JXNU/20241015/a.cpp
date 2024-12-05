#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector a(n + 2, vector<i64>(m + 2));

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            a[i][j] = min(i - 1, j - 1) + min(i - 1, m + 1 - j) + min(n + 1 - i, j - 1) + min(n + 1 - i, m + 1 - j);
            a[i][j] += min({int((i - 1) / 1.414), int((j - 1) / 0.707), int((m + 1 - j) / 0.707)});
            a[i][j] += min({int((n + 1 - i) / 1.414), int((j - 1) / 0.707), int((m + 1 - j) / 0.707)});
            a[i][j] += min({int((j - 1) / 1.414), int((i - 1) / 0.707), int((n + 1 - i) / 0.707)});
            a[i][j] += min({int((m + 1 - j) / 1.414), int((i - 1) / 0.707), int((n + 1 - i) / 0.707)});
        }
    }

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            // a[i][j] = min({a[i][j], a[i][m + 2 - j], a[n + 2 - i][j], a[n + 2 - i][m + 2 - j]});
        }
    }

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            cout << a[i][j] << " \n"[j == m + 1];
        }
    }

    return 0;
}