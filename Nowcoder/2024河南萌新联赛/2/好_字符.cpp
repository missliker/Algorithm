#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> zFunction(string b) {
    int n_ = b.size();
    vector<int> z(n_ + 1);
    z[0] = n_;
    for (int i = 1, j = 1; i < n_; i++) {
        z[i] = max(0, min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n_ and b[z[i]] == b[i + z[i]]) z[i] += 1;
        if (i + z[i] > j + z[j]) j = i;
    }
    return z;
}

vector<int> pFunction(string a, string b, vector<int>& z) {
    int n_ = a.size();
    int m_ = b.size();
    vector<int> p(n_ + 1);
    p[0] = n_;
    for (int i = 0, j = 1; i < n_; i++) {
        p[i] = max(0, min(j + p[j] - i, z[i - j]));
        while (p[i] < m_ and i + p[i] < n_ and b[p[i]] == a[i + p[i]]) p[i] += 1;
        if (i + p[i] > j + p[j]) j = i;
    }
    return p;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    string a, b;
    cin >> n >> a >> b;
    a += a.substr(0, n - 1);
    set<char> st;
    for (auto& i : a) st.insert(i);

    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (st.find(c) == st.end()) continue;
        auto s = a, t = b;
        for (auto& i : s) {
            if (i != c) i = '#';
        }
        for (auto& i : t) {
            if (i != c) i = '#';
        }

        auto z = zFunction(t);
        auto p = pFunction(s, t, z);

        bool ok = false;
        for (int i = 1; i <= s.size(); i++) {
            if (p[i] == t.size()) {
                ok = true;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << '\n';

    return 0;
}