#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
struct Hash {
    const int BASE1 = 31, BASE2 = 37;
    const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    vector<i64> Hash1, Hash2, Power1, power2;

    Hash(const string& str) {
        int n = str.size();
        Hash1.assign(n + 1, 0);
        Hash2.assign(n + 1, 0);
        Power1.assign(n + 1, 1);
        power2.assign(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
            Hash1[i] = (Hash1[i - 1] * BASE1 + str[i - 1]) % mod1;
            Hash2[i] = (Hash2[i - 1] * BASE2 + str[i - 1]) % mod2;
            Power1[i] = (Power1[i - 1] * BASE1) % mod1;
            power2[i] = (power2[i - 1] * BASE2) % mod2;
        }
    }

    Pair get(int l, int r) {
        i64 hash1 = ((Hash1[r] - Hash1[l - 1] * Power1[r - l + 1]) % mod1 + mod1) % mod1;
        i64 hash2 = ((Hash2[r] - Hash2[l - 1] * power2[r - l + 1]) % mod2 + mod2) % mod2;
        return {hash1, hash2};
    }
};

void Solution(int T) {
    string s, t;
    cin >> s;
    t = s;
    ranges::reverse(t);
    if (t == s) {
        cout << "Yes\n";
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s.size() >= i + 1 and s[i] == s[s.size() - 1 - i]) continue;
        s = s.substr(i, s.size() - i * 2);
        break;
    }

    Hash hs(s);
    bool ok = false;
    for (int i = 0; i < s.size(); i++) {
        if ((s.size() - i) % 2 == 0) {
            int len = (s.size() - i) / 2;
            if (hs.get(i + 1, i + len) == hs.get(i + len + 1, i + len * 2)) {
                t = s.substr(0, i);
                ranges::reverse(t);
                if (t == s.substr(0, i)) {
                    if (s.substr(i, len) == s.substr(i + len, len)) {
                        ok = true;
                        break;
                    }
                }
            }
        }
    }
    if (ok) {
        cout << "Yes\n";
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (i & 1) {
            int len = (i + 1) / 2;
            if (hs.get(0 + 1, len) == hs.get(len + 1, len * 2)) {
                t = s.substr(i + 1);
                ranges::reverse(t);
                if (t == s.substr(i + 1)) {
                    if (s.substr(0, len) == s.substr(len, len)) {
                        ok = true;
                        break;
                    }
                }
            }
        }
    }
    if (ok) {
        cout << "Yes\n";
        return;
    }

    for (int len = 1; len <= s.size(); len++) {
        if (s.size() >= len * 2 and hs.get(0 + 1, len) == hs.get(s.size() - len + 1, s.size())) {
            t = s.substr(len, s.size() - len * 2);
            ranges::reverse(t);
            if (t == s.substr(len, s.size() - len * 2)) {
                if (s.substr(0, len) == s.substr(s.size() - len, len)) {
                    ok = true;
                    break;
                }
            }
        }
    }
    if (ok) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}