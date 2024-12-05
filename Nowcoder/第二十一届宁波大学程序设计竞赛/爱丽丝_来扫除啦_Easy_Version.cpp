#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using ld = long double;
constexpr i64 INF = 1E15 + 10;

struct Info {
    i64 x, y, p;
};

bool operator<(const Info& a, const Info& b) {
    if (a.x == b.x and a.y == b.y) return a.p < b.p;
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    map<Info, int> mp;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int p;
        if (x == 0) {
            if (y == 0) {
                zero++;
                continue;
            }
            if (y > 0) p = 6;
            else if (y < 0) p = 8;
            mp[{INF, INF, p}]++;
            continue;
        }
        if (y == 0) {
            if (x > 0) p = 5;
            else p = 7;
            mp[{0, 0, p}]++;
            continue;
        }
        if (x > 0) {
            if (y > 0) p = 1;
            else p = 4;
        } else {
            if (y > 0) p = 2;
            else p = 3;
        }
        int k = gcd(x, y);
        x /= k, y /= k;
        mp[{x, y, p}]++;
    }
    int ans = 0;
    for (auto& [info, cnt] : mp) ans = max(ans, cnt);
    cout << ans + zero << '\n';

    return 0;
}