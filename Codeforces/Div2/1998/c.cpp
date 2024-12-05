#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector arr(2, vector<int>());
    for (int i = 0; i < n; i++) {
        arr[b[i]].emplace_back(a[i]);
    }
    ranges::sort(arr[0]);
    ranges::sort(arr[1]);
    i64 ans = 0;
    if (not arr[1].empty()) {
        ans = arr[1].back() + k;
        auto v = arr[0];
        for (int i = 0; i < arr[1].size() - 1; i++) {
            v.emplace_back(arr[1][i]);
        }
        ranges::sort(v);
        ans += v[n / 2 - 1];
    }
    if (arr[0].empty()) {
        cout << ans << '\n';
        return;
    }

    i64 t = arr[0].back();
    arr[0].pop_back();

    auto check = [&](i64 x) -> bool {
        int p = ranges::lower_bound(arr[0], x) - begin(arr[0]);
        if (p >= n / 2) {
            return false;
        }
        i64 cost = 0;
        for (int i = n / 2 - p - 1; i < arr[1].size(); i++) {
            if (arr[1][i] < x) {
                cost += x - arr[1][i];
            }
            if (cost > k) return false;
        }
        return true;
    };

    i64 lo = 0, hi = 1E18;
    while (lo < hi) {
        i64 mi = (lo + hi + 1LL) >> 1LL;
        if (check(mi)) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    ans = max(ans, hi + t);
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