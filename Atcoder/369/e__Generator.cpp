#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

i64 intRand(i64 mod) { return rng() * rng() % mod; }

i64 intRand(i64 l, i64 r) { return l + intRand(r - l + 1); }

char smallCharRand() { return char('a' + intRand(26)); }

char bigCharRand() { return char('A' + intRand(26)); }

string smallStringRand(i64 n) {
    string res;
    for (int i = 0; i < n; i++) {
        res += smallCharRand();
    }
    return res;
}

string bigStringRand(i64 n) {
    string res;
    for (int i = 0; i < n; i++) {
        res += bigCharRand();
    }
    return res;
}

vector<i64> vectorRand(i64 n, i64 l, i64 r) {
    vector<i64> res;
    for (int i = 0; i < n; i++) {
        i64 x = intRand(l, r);
        res.emplace_back(x);
    }
    return res;
}

vector<Pair> treeRand(i64 n) {
    vector<Pair> tree;
    for (int i = 2; i <= n; i++) {
        i64 u = i, v = intRand(1, i - 1);
        tree.emplace_back(u, v);
    }
    return tree;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    // freopen("./Hacker.in", "w", stdout);
    // random_shuffle(v.begin(), v.end());

    int t = 1;
    // cout << t << endl;
    while (t--) {
        int n = intRand(2, 6), m = intRand(4, 6);
        cout << n << ' ' << m << endl;
        for (int i = 1; i <= m; i++) {
            int u = intRand(1, n), v = intRand(1, n), w = intRand(1, 10);
            while (u == v) {
                v = intRand(1, n);
            }
            cout << u << ' ' << v << ' ' << w << endl;
        }
        cout << 1 << endl;
        int k = intRand(2, n);
        set<int> b;
        for (int i = 1; i <= k; i++) {
            b.insert(intRand(1, m));
        }
        k = b.size();
        cout << k << endl;
        for (auto& x : b) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}