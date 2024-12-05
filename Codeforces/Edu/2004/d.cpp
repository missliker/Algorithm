#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    map<string, set<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i][0] > s[i][1]) {
            swap(s[i][0], s[i][1]);
        }
        mp[s[i]].insert(i);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) {
            swap(x, y);
        }
        int ans = 2 * n;
        for (char& c : string("BGRY")) {
            if (s[x].find(c) != string::npos and s[y].find(c) != string::npos) {
                ans = y - x;
                break;
            }
        }
        if (ans < 2 * n) {
            cout << ans << '\n';
            continue;
        }

        for (char& a : s[x]) {
            for (char& b : s[y]) {
                string now = string("") + min(a, b) + max(a, b);
                auto it = mp[now].lower_bound(x);
                if (it == mp[now].end()) {
                    if (it != mp[now].begin()) {
                        it--;
                        ans = min(ans, abs(x - *it) + abs(y - *it));
                    }
                    continue;
                }
                ans = min(ans, abs(x - *it) + abs(y - *it));
                if (it != mp[now].begin()) {
                    it--;
                    ans = min(ans, abs(x - *it) + abs(y - *it));
                }
            }
        }
        if (ans == 2 * n) {
            ans = -1;
        }
        cout << ans << '\n';
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