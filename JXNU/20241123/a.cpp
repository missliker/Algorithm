#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    getline(cin, s);
    int n;
    cin >> n;
    string ns;
    for (auto& c : s) {
        c = tolower(c);
        if (c >= 'a' and c <= 'z' or c == ' ') {
            ns += c;
        }
    }
    s = ns;
    ns = "";
    debug(s);
    debug(n);

    set<string> st;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        for (auto& c : t) {
            c = tolower(c);
        }
        st.insert(t);
    }

    int ans = 0;
    for (int i = 0; i < s.size();) {
        int j = i;
        while (j < s.size() and s[j] != ' ') {
            ns += s[j];
            j++;
        }
        if (st.find(ns) == st.end()) {
            ans++;
            st.insert(ns);
        }
        debug(ns);
        i = j + 1;
        ns = "";
    }
    cout << ans << '\n';

    return 0;
}