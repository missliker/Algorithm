#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 N, M;
    cin >> N >> M;
    vector<int> A(N);
    i64 s = 0;
    for (auto& i : A) {
        cin >> i;
        s += i;
    }
    if (s <= M) {
        cout << "infinite\n";
        return 0;
    }

    auto check = [&](int x) -> bool {
        i64 res = 0;
        for (auto& i : A) {
            res += min(x, i);
        }
        return res <= M;
    };

    int lo = 0, hi = ranges::max(A);
    while (lo < hi) {
        int mi = (lo + hi + 1) >> 1;
        if (check(mi)) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    cout << hi << '\n';

    return 0;
}