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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, t;
    cin >> n >> t;
    vector<Pair> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = n + 1 - i;
        if (i == 1) a[i].second = 0;
    }
    sort(a.begin() + 1, a.end(), [&](Pair i, Pair j) {
        if (i.first == j.first) return i.second < j.second;
        return i.first > j.first;
    });
    for (int i = 1; i <= n; i++) {
        if (a[i].second <= t) {
            cout << a[i].second << '\n';
            return 0;
        }
    }

    return 0;
}