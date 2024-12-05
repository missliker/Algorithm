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

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> L(n), R(n), Y(n);
    map<int, set<Pair>> mp;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i] >> Y[i];
        mp[Y[i]].insert({L[i], R[i]});
    }
    i64 sx, sy;
    cin >> sx >> sy;
    auto H = Y;
    sort(H.begin(), H.end());
    H.erase(unique(H.begin(), H.end()), H.end());

    while (sy >= 0) {
        bool ok = true;
        for (auto& [l, r] : mp[sy]) {
            if (ok) {
                ok = false;
                if (sx > l and sx <= r) sx = max(sx, r);
                continue;
            }
            if (sx >= l and sx <= r) sx = max(sx, r);
        }
        int j = lower_bound(H.begin(), H.end(), sy) - H.begin();
        if (j == 0) break;
        sy = H[j - 1];
    }
    cout << sx << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}