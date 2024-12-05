#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, x;
    cin >> n >> x;

    set<i64> st;
    for (i64 i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            if (i <= n) st.insert(i);
            if (x / i != i and x / i <= n) st.insert(x / i);
        }
    }
    i64 ans = st.size();
    cout << (ans % 2 == 0 ? "OFF" : "ON") << '\n';

    return 0;
}