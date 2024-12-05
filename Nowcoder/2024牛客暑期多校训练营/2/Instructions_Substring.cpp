#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
ostream& operator<<(ostream& os, Pair n) {
    string a, b, s, flag;
    if (n.first < 0) flag = "-", n.first *= -1;
    while (n.first) {
        a += '0' + n.first % 10;
        n.first /= 10;
    }
    a += flag;
    reverse(a.begin(), a.end());
    flag = string("");
    if (n.second < 0) flag = "-", n.second *= -1;
    while (n.second) {
        b += '0' + n.second % 10;
        n.second /= 10;
    }
    b += flag;
    reverse(b.begin(), b.end());
    s = "[" + a + ", " + b + "]\n";
    return os << s;
}
#define deg(a) cerr << #a << " = " << a << ' ';
#define bug(a) cerr << #a << " = " << a << '\n';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, end_x, end_y;
    cin >> n >> end_x >> end_y;
    string s;
    cin >> s;
    if (end_x == 0 and end_y == 0) {
        cout << 1LL * (n + 1) * n / 2 << '\n';
        return 0;
    }
    vector<int> x(n + 1), y(n + 1);
    for (int i = 0; i < n; i++) {
        x[i + 1] = x[i], y[i + 1] = y[i];
        if (s[i] == 'W') {
            y[i + 1] += 1;
        } else if (s[i] == 'S') {
            y[i + 1] -= 1;
        } else if (s[i] == 'D') {
            x[i + 1] += 1;
        } else {
            x[i + 1] -= 1;
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        deg(x[i]);
        bug(y[i]);
    }
    map<Pair, int> mp;
    mp[{0, 0}] = 1;
    for (int i = 1; i <= n; i++) {
        if (mp.count({x[i] - end_x, y[i] - end_y})) ans += 1LL * mp[{x[i] - end_x, y[i] - end_y}] * (n - i + 1);
        mp[{x[i], y[i]}]++;
    }
    cout << ans << '\n';

    return 0;
}