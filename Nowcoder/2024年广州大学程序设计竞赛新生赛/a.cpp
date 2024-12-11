#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
const i64 INF = numeric_limits<i64>::max();

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    map<string, map<char, Pair>> mp;
    for (int i = 1; i <= n; i++) {
        string name;
        char id;
        int flag, time;
        cin >> name >> id >> flag >> time;
        if (flag) {
            if (mp[name][id].second != INF) {
                mp[name][id].first += time;
                mp[name][id].second = INF;
            }
        } else {
            if (mp[name][id].second != INF) {
                mp[name][id].first += 20;
            }
        }
    }

    map<string, Pair> ans;
    Pair mx = {0, 0};
    string res;
    for (auto& [name, m] : mp) {
        for (auto& [id, pa] : m) {
            auto [x, y] = pa;
            if (y == INF) {
                ans[name].first++;
                ans[name].second += x;
            }
        }
        if (ans[name].first > mx.first) {
            mx = ans[name];
            res = name;
        } else if (ans[name].first == mx.first and ans[name].second < mx.second) {
            mx = ans[name];
            res = name;
        }
    }
    cout << res << ' ' << mx.first << ' ' << mx.second << '\n';

    return 0;
}