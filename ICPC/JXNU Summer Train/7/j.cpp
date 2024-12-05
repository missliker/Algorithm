#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    auto chmax = [&](int a, int k) {
        if (a >> k & 1) return a;
        a = (a >> k | 1) << k;
        return a;
    };

    i64 ans = 0;
    for (int k = 30; k >= 0; k--) {
        i64 x = 1LL << k;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (chmax(l[i], k) > r[i]) {
                ok = false;
                break;
            }
        }
        if (not ok) continue;
        ans |= x;
        for (int i = 0; i < n; i++) {
            l[i] = chmax(l[i], k);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}