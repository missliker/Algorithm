#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        ans += x;
    }
    cout << (ans > 100 ? "YES" : "NO") << '\n';

    return 0;
}