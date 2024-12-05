#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n;
    cin >> n;
    if (n < 0) {
        cout << "negative\n";
    } else {
        cout << "non-negative\n";
    }

    return 0;
}