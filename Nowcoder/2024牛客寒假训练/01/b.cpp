#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int n;
    cin >> n;
    set<i64> l1, l2, r1, r2;
    for (int i = 1; i <= n; i++) {
        i64 x, y;
        cin >> x >> y;
        if (x == 1) {
            if (y <= 0) l1.insert(y);
            if (y >= 0) r1.insert(y); 
        } else {
            if (y <= 0) l2.insert(y);
            if (y >= 0) r2.insert(y);
        }
    }
    int l = 1;
    for (auto x : l1) {
        if (l2.contains(x) or l2.contains(x - 1) or l2.contains(x + 1)) l = 0;
    }
    if (l1.empty() and l2.empty()) l = 2;
    int r = 1;
    for (auto x : r1) {
        if (r2.contains(x) or r2.contains(x - 1) or r2.contains(x + 1)) r = 0;
    }
    if (r1.empty() and r2.empty()) r = 2;
    cout << l + r << '\n';
}
int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}
