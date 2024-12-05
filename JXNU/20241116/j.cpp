#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using d32 = double;
using d64 = long double;
using Pair = pair<d32, d32>;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<Pair> merge(vector<Pair>& segs) {
    vector<Pair> res;
    ranges::sort(segs);
    for (auto& p : segs) {
        if (not res.empty() and p.first <= res.back().second) {
            res.back().second = max(res.back().second, p.second);
        } else {
            res.emplace_back(p);
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    d32 x0, y0;
    int k;
    cin >> x0 >> y0 >> k;
    vector<Pair> lins;
    for (int i = 0; i < k; i++) {
        d32 xd, yd, rd;
        cin >> xd >> yd >> rd;
        d32 h = fabs(yd - y0);
        if (rd <= h) {
            continue;
        }
        d32 d = sqrt(rd * rd - h * h);
        d32 l = xd - d, r = xd + d;
        l = max(l, x0), r = max(r, x0);
        lins.emplace_back(l, r);
    }

    lins = merge(lins);
    debug(lins);

    d32 ans = 0;
    for (auto [l, r] : lins) {
        ans += r - l;
    }
    cout << ans << '\n';

    return 0;
}