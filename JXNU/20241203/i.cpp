#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

struct DSU {
    vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { iota(f.begin(), f.end(), 0); }

    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }

    bool same(int x, int y) { return leader(x) == leader(y); }

    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) { return siz[leader(x)]; }
};

void Solution(int curCase) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dsu.merge(i, a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == dsu.leader(i)) {
            ans++;
        }
    }
    cout << ans - 1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int maxCase = 1;
    cin >> maxCase;
    for (int curCase = 1; curCase <= maxCase; curCase++) {
        Solution(curCase);
    }

    return 0;
}