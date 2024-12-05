#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    string s;
    cin >> s;

    set<string> st;
    for (int len = 1; len <= s.size(); len++) {
        for (int l = 0; l + len - 1 < s.size(); l++) {
            int r = l + len;
            // debug(l, r);
            auto t = s;
            reverse(t.begin() + l, t.begin() + r);
            st.insert(t);
        }
    }
    for (auto& x : st) {
        debug(x);
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