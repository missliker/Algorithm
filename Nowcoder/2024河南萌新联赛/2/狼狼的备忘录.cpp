#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    map<string, set<string>> mp;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            mp[name].insert(s);
        }
    }

    map<string, set<string>> ans;
    for (auto& [name, st] : mp) {
        auto t = vector<string>(st.begin(), st.end());
        sort(t.begin(), t.end(), [&](string lth, string rth) {
            if (lth.size() == rth.size()) return lth < rth;
            return lth.size() > rth.size();
        });
        set<string> have;
        for (auto s : t) {
            if (have.find(s) != have.end()) continue;
            ans[name].insert(s);
            for (int l = 0; l < s.size(); l++) {
                have.insert(s.substr(l));
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto& [name, st] : ans) {
        cout << name << ' ' << st.size() << ' ';
        for (auto& s : st) cout << s << ' ';
        cout << '\n';
    }

    return 0;
}