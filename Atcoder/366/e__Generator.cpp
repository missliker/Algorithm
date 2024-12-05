#include <bits/stdc++.h>
#include <cstdint>
#include <numeric>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

i64 intRand(i64 mod, int base = 0) { return rng() * rng() % mod + base; }

char smallCharRand(i64 mod) { return char('a' + rng() * rng() % mod); }

char bigCharRand(i64 mod) { return char('A' + rng() * rng() % mod); }

string smallStringRand(i64 n) {
    string res;
    for (int i = 0; i < n; i++) {
        char ch = 'a' + rng() % 26;
        res += ch;
    }
    return res;
}

string bigStringRand(i64 n) {
    string res;
    for (int i = 0; i < n; i++) {
        char ch = 'A' + rng() % 26;
        res += ch;
    }
    return res;
}

vector<i64> vectorRand(i64 n, i64 mod) {
    vector<i64> res;
    for (int i = 0; i < n; i++) {
        i64 x = intRand(mod, 1);
        res.emplace_back(x);
    }
    return res;
}

vector<Pair> treeRand(i64 n) {
    vector<Pair> tree;
    for (int i = 2; i <= n; i++) {
        i64 u = i, v = intRand(i - 1, 1);
        tree.push_back({u, v});
    }
    return tree;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    // freopen("./data.txt", "w", stdout);

    // auto v = vectorRand(n, 30);
    // sort(v.begin(), v.end());
    // for (auto x : v) cout << x << ' ';
    // vector<int> v(n);
    // iota(v.begin(), v.end(), 1);
    // random_shuffle(v.begin(), v.end());
    // for (auto x : v) cout << x << ' ';

    int t = 1;
    // cout << t << endl;
    while (t--) {
        int n = intRand(10, 1), q = intRand(1E6, 1);
        // cout << n << ' ' << q << endl;
        set<Pair> st;
        for (int i = 0; i < n; i++) {
            int x = intRand(1E6, -1E6), y = intRand(1E6, -1E6);
            st.insert({x, y});
        }
        cout << st.size() << ' ' << q << endl;
        for (auto [x, y] : st) {
            cout << x << ' ' << y << endl;
        }
    }
    return 0;
}