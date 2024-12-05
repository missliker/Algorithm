#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto check = [&](int k) -> bool {
        i64 maxl = 0, minr = 1E18;
        for (int i = 0; i < n; i++) {
            maxl = max(maxl, a[i] - 1LL * k * b[i]);
            minr = min(minr, a[i] + 1LL * k * b[i]);
        }
        return maxl <= minr;
    };

    int lo = 0, hi = 1E9;
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        if (check(mi)) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << hi << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}