#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    if (n & 1) {
        cout << -1;
    } else {
        cout << n / 2 << ' ' << n / 2;
    }

    return 0;
}