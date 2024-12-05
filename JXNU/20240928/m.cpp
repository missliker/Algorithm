#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;

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
    set<Pair> st;
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	st.insert({x, y});
    }

    long double ans = 2.0 * st.size();
    constexpr int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    constexpr int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
    for (auto [x, y] : st) {
    	for (int i = 0; i < 4; i++) {
    		int nx = x + dx[i], ny = y + dy[i];
    		if (st.find({nx, ny}) != st.end()) {
    			ans -= 0.25;
    		}
    	}
    }
    cout << ans << '\n';

    return 0;
}