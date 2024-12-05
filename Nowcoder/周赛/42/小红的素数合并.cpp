#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
#define deg(a) cerr << #a << " == " << a << ' ';
#define bug(a) cerr << #a << " == " << a << '\n';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    ranges::sort(a);
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    if (n == 3) {
        cout << abs(a[0] * a[1] - a[2]) << '\n';
        return 0;
    }

    multiset<i64> st;
    for (auto x : a) { st.insert(x); }
    bool bg = true;
    i64 lst, l = 0, r = 1E18;
    for (auto x : st) {
        if (bg) {
            bg = false;
            lst = x;
            continue;
        }
        if (x - lst < r - l) { r = x, l = lst; }
        lst = x;
    }
    auto itl = st.lower_bound(l);
    st.erase(itl);
    auto itr = st.lower_bound(r);
    st.erase(itr);
    // for (auto x : st) cout << x << ' ';

    bg = true;
    i64 l2 = 0, r2 = 1E18;
    for (auto x : st) {
        if (bg) {
            bg = false;
            lst = x;
            continue;
        }
        if (x - lst < r2 - l2) { r2 = x, l2 = lst; }
        lst = x;
    }
    deg(l);
    deg(r);
    deg(l2);
    bug(r2);

    cout << min({abs(l * l2 - r * r2), abs(l * r2 - r * l2), abs(l * r - l2 * r2)}) << '\n';

    return 0;
}