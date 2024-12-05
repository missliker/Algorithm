#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (auto& i : a) cin >> i;
    ranges::sort(a);

    while (Q--) {
        int b, k;
        cin >> b >> k;
        int lo = 0, hi = 1E9 + 10;
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            int l = ranges::lower_bound(a, b - mi) - begin(a);
            int r = ranges::upper_bound(a, b + mi) - begin(a);
            int cnt = r - l;
            if (cnt >= k) hi = mi;
            else lo = mi + 1;
        }
        cout << hi << '\n';
    }

    return 0;
}