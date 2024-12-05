#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
#define de(a)  cout << #a << ": " << a << ' ';
#define bug(a) cout << #a << ": " << a << '\n';

i64 mul(i64 a, i64 b, i64 m) { return static_cast<__int128>(a) * b % m; }

i64 power(i64 a, i64 b, i64 m) {
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1) res = mul(res, a, m);
    return res;
}

bool isprime(i64 n) {
    if (n < 2) return false;
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    i64 d = (n - 1) >> s;
    for (auto a : A) {
        if (a == n) return true;
        i64 x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool ok = false;
        for (int i = 0; i < s - 1; ++i) {
            x = mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}

vector<Pair> factorize(i64 n) {
    map<i64, i64> p;
    function<void(i64)> f = [&](i64 n) {
        if (n <= 10000) {
            for (int i = 2; i * i <= n; ++i)
                for (; n % i == 0; n /= i) p[i]++;
            if (n > 1) p[n]++;
            return;
        }
        if (isprime(n)) {
            p[n]++;
            return;
        }
        auto g = [&](i64 x) {
            return (mul(x, x, n) + 1) % n;
        };
        i64 x0 = 2;
        while (true) {
            i64 x = x0;
            i64 y = x0;
            i64 d = 1;
            i64 power = 1, lam = 0;
            i64 v = 1;
            while (d == 1) {
                y = g(y);
                ++lam;
                v = mul(v, abs(x - y), n);
                if (lam % 127 == 0) {
                    d = gcd(v, n);
                    v = 1;
                }
                if (power == lam) {
                    x = y;
                    power *= 2;
                    lam = 0;
                    d = gcd(v, n);
                    v = 1;
                }
            }
            if (d != n) {
                f(d);
                f(n / d);
                return;
            }
            ++x0;
        }
    };
    f(n);
    vector<Pair> tmp;
    for (auto& [x, y] : p) {
        tmp.emplace_back(x, y);
    }
    return tmp;
}

void Solution(int T) {
    i64 n;
    cin >> n;

    auto s = [&](i64 x) -> int {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    };

    vector<i64> ans;
    for (int sm = 1; sm <= 12 * 9; sm++) {
        i64 x = n - sm;
        if (x <= 0) continue;
        auto p = factorize(x);
        vector<i64> prime{1};
        i64 res = 1;
        auto dfs = [&](auto self, int i) -> void {
            if (i == p.size()) {
                prime.emplace_back(res);
                return;
            }
            for (int cnt = 0; cnt <= p[i].second; cnt++) {
                res *= pow(p[i].first, cnt);
                self(self, i + 1);
                res /= pow(p[i].first, cnt);
            }
        };
        dfs(dfs, 0);
        sort(prime.begin(), prime.end());
        prime.erase(unique(prime.begin(), prime.end()), prime.end());
        for (auto& k : prime) {
            if (x % k != 0) continue;
            i64 m = x / k;
            if (n % m == s(m)) {
                ans.emplace_back(m);
            }
            if (k != m and n % k == s(k)) {
                ans.emplace_back(k);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}