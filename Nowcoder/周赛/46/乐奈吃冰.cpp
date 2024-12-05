#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 a, b;
    cin >> a >> b;
    cout << a + min(a / 2, b) << '\n';

    return 0;
}