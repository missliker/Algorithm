#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    while (m--) {
        map<int, set<char>> dic;
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            dic[a[i]].insert(s[i]);
        }
        bool ok = true;
        for (auto& [x, st] : dic) {
            if (st.size() != 1) {
                ok = false;
                break;
            }
        }
        if (not ok) {
            cout << "NO\n";
            continue;
        }
        ok = true;
        map<char, int> st;
        for (int i = 0; i < n; i++) {
            if (not st.count(s[i])) {
                st[s[i]] = a[i];
            } else {
                if (st[s[i]] == a[i]) continue;
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
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