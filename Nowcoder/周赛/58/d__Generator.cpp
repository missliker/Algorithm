#include <bits/stdc++.h>
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
    cout << t << endl;
    while (t--) {
        i64 n = intRand(1, 1E18), k = intRand(1, 10);
        cout << n << ' ' << k << endl;
    }
    return 0;
}