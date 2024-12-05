#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
typedef pair<int, int> PII;
#define x first
#define y second

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    set<PII> st;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    int ans = 0, add = 0;
    for (auto [x, y] : st) {
        if (st.find({x - 1, y}) == st.end()) ans += 1;
        else add += 1;
        if (st.find({x, y - 1}) == st.end()) ans += 1;
        else add += 1;
        if (st.find({x + 1, y}) == st.end()) ans += 1;
        else add += 1;
        if (st.find({x, y + 1}) == st.end()) ans += 1;
        else add += 1;
    }
    ans += add / 2;
    cout << ans << '\n';
    return 0;
}
