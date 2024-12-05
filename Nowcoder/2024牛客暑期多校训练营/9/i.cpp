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
    i64 La = L / P, Lb = L % P;
    i64 Ra = R / P, Rb = R % P;

    auto check = [&](i64 x) {
        i64 y = sqrtl(x);
        return y * y == x;
    };

    i64 lo = 0, hi = 1E15;
    while (lo < hi) {
        i64 mi = (lo + hi) >> 1LL;
        if (i128(1) * mi * mi >= La) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    i64 Llo = hi;
    if (check(La)) Llo++;

    lo = 0, hi = 1E15;
    while (lo < hi) {
        i64 mi = (lo + hi + 1) >> 1LL;
        if (i128(1) * mi * mi <= Ra) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    i64 Lhi = hi;
    if (check(Ra)) Lhi--;

    lo = 0, hi = 1E15;
    while (lo < hi) {
        i64 mi = (lo + hi + 1) >> 1LL;
        if (i128(1) * mi * mi <= P - 1) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    i64 cnt = hi;
    i64 ans = (Lhi - Llo + 1) * cnt;
    cout << ans << endl;

    if (check(La)) {
        lo = 0, hi = 1E15;
        while (lo < hi) {
            i64 mi = (lo + hi) >> 1LL;
            if (i128(1) * mi * mi >= Lb) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        ans += cnt - hi + 1;
    }
    cout << ans << endl;

    if (check(Ra)) {
    	lo = 0, hi = 1E15;
    	while (lo < hi) {
    		i64 mi = (lo + hi) >> 1LL;
    		if (i128(1) * mi * mi <= Rb) {
    			lo = mi;
    		} else {
    			hi = mi - 1;
    		}
     	}
     	ans += hi;
    }

    cout << ans << '\n';

    return 0;
}