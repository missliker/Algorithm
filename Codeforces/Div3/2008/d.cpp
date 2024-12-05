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

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) {
        cin >> x;
        x--;
    }
    string s;
    cin >> s;

    DSU dsu(n);
    vector<int> f(n, 0);
    for (int i = 0; i < n; i++) {
        f[i] = 1 - (s[i] - '0');
    }
    for (int i = 0; i < n; i++) {
        if (dsu.leader(i) != i) {
            continue;
        }
        int j = p[i];
        while (j != i) {
            dsu.merge(i, j);
            if (s[j] == '0') {
                f[i] += f[j];
            }
            j = p[j];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << f[dsu.leader(i)] << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}