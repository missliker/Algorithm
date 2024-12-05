#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
ostream& operator<<(ostream& os, i128 n) {
    string s, flag;
    if (n < 0) flag = "-", n *= -1;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    s += flag;
    reverse(s.begin(), s.end());
    return os << s;
}

i128 gcd(i128 a, i128 b) { return b ? gcd(b, a % b) : a; }

i128 abs(i128 a) { return max(a, -a); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    i64 L, R;
    cin >> n >> L >> R;
    i64 P = pow(10LL, n / 2);
    i64 ans = 0;
    for (i64 i = L; i <= R; i++) {
        i64 ia = i / P, ib = i % P;

        auto check = [&](i64 x) {
            i64 y = sqrtl(x);
            return y * y == x;
        };

        if (check(ia) and check(ib)) {
            // cout << i << endl;
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}