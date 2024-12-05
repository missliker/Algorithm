#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using ld = long double;
typedef pair<i64, i64> Pair;
typedef tuple<i64, i64, Pair> Tuple;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(1);

    int n;
    cin >> n;
    vector<Pair> p(n);
    for (auto& [x, y] : p) cin >> x >> y;
    vector<Tuple> line;
    for (int i = 0; i < n; i++) {
        auto [ax, ay] = p[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto [bx, by] = p[j];
            line.push_back({ax - bx, ay - by, {i, j}});
            // line.push_back({ax - by, ay - bx, {i, j}});
            // line.push_back({bx - ax, by - ay, {i, j}});
            // line.push_back({bx - ay, by - ax, {i, j}});
        }
    }
    sort(line.begin(), line.end());
    // for (auto [dx, dy, ij] : line) { cout << dx << ' ' << dy << ' ' << ij.first << ' ' << ij.second << endl; }
    map<Pair, Pair> mp;
    vector<Pair> fa;
    for (auto [dx, dy, ij] : line) {
        mp[ij] = {dx, dy};
        fa.push_back({dx, dy});
    }
    fa.erase(unique(fa.begin(), fa.end()), fa.end());

    constexpr Pair daf = {-1E18, -1E18};
    // Pair lst = daf;
    vector<vector<Pair>> qry(fa.size());
    for (auto [dx, dy, ij] : line) {
        Pair now = {dx, dy};
        int i = lower_bound(fa.begin(), fa.end(), now) - fa.begin();
        qry[i].push_back(ij);
    }

    auto dis = [&](Pair a, Pair b) -> ld {
        auto [ax, ay] = a;
        auto [bx, by] = b;
        ld res = 1.0 * (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
        return sqrtl(res);
    };

    auto calc = [&](Pair a, Pair b, Pair c) -> ld {
        auto [ax, ay] = a;
        auto [bx, by] = b;
        auto [cx, cy] = c;
        ld la = dis(b, c), lb = dis(a, c), lc = dis(a, b), lp = (la + lb + lc) / 2.0;
        return sqrtl(lp * (lp - la) * (lp - lb) * (lp - lc)) * 2.0;
    };

    ld ans = 1E18;
    for (int i = 0; i < qry.size(); i++) {
        for (int j = 0; j < qry[i].size(); j++) {
            auto [a, b] = qry[i][j];
            for (int k = j + 1; k < qry[i].size(); k++) {
                auto [c, d] = qry[i][k];
                set<int> st{a, b, c, d};
                if (st.size() != 4) continue;
                if (mp[{a, c}] == mp[{b, d}]) {
                    ld res = calc(p[a], p[b], p[c]);
                    if (res > 0.000001) ans = min(ans, res);
                } else if (mp[{a, d}] == mp[{b, c}]) {
                    ld res = calc(p[b], p[a], p[c]);
                    if (res > 0.000001) ans = min(ans, res);
                }
            }
        }
    }
    if (ans == 1E18) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';

    bool flag = false;
    cout << boolalpha << flag << '\n';

    return 0;
}