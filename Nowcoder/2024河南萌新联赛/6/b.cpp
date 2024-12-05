#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int findPrime(int n) {
    while (!isprime(n)) n++;
    return n;
}

using Pair = pair<i64, i64>;
struct Hash {
    static int mod1, mod2;
    const int BASE1 = 31, BASE2 = 37;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Hash::mod1 = findPrime(rng() % 900000000 + 100000000);
int Hash::mod2 = findPrime(rng() % 900000000 + 100000000);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s, t;
    cin >> s >> t;
    Hash hs(s), ht(t);

    map<int, char> ans;
    if (hs.get(1, s.size()) == ht.get(2, t.size())) {
        ans[0] = t[0];
    }
    for (int i = 1; i < s.size(); i++) {
        if (hs.get(1, i) == ht.get(1, i) and hs.get(i + 1, s.size()) == ht.get(i + 2, t.size())) {
            debug(s.substr(0, i));
            ans[i] = t[i];
        }
    }
    if (hs.get(1, s.size()) == ht.get(1, s.size())) {
    	ans[s.size()] = t.back();
    }
    cout << ans.size() << '\n';
    for (auto& [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}