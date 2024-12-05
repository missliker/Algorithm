#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

const int N = 210;
int f[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    memset(f, -1, sizeof f);
    while (cin >> n >> m and n) {
        auto sg = [&](auto self, int a, int b) -> int {
            if (f[a][b] != -1) {
                return f[a][b];
            }

            set<int> s;
            for (int i = 2; i <= a - 2; i++) {
                s.insert(self(self, i, b) ^ self(self, a - i, b));
            }
            for (int i = 2; i <= b - 2; i++) {
                s.insert(self(self, a, i) ^ self(self, a, b - i));
            }

            for (int i = 0;; i++) {
                if (not s.count(i)) return f[a][b] = f[b][a] = i;
            }
        };

        cout << (sg(sg, n, m) ? "WIN" : "LOSE") << '\n';
    }

    return 0;
}