#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Trie {
    struct node {
        array<int, 26> son;
        int cnt = 0;
        node() : son{} {}
    };

    vector<node> t;

    Trie() { init(); }

    void init() { t.assign(1, node()); }

    int New() {
        t.emplace_back();
        return t.size() - 1;
    }

    void insert(const string& s) {
        int p = 0;
        for (auto& c : s) {
            int u = c - 'a';
            if (!t[p].son[u]) t[p].son[u] = New();
            p = t[p].son[u];
        }
        t[p].cnt++;
    }

    int query(const string& s) {
        int p = 0, res = 0;
        for (auto& c : s) {
            int u = c - 'a';
            p = t[p].son[u];
            res += t[p].cnt;
        }
        return res;
    }
} trie;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<string> S(N);
    for (auto& s : S) cin >> s;
    sort(S.begin(), S.end(), [&](string L, string R) { return L.size() < R.size(); });

    int ans = 0;
    for (auto& s : S) {
        trie.insert(s);
        ans = max(ans, trie.query(s));
    }
    cout << ans << '\n';

    return 0;
}