#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define deg(a) cout << #a << " == " << a << ' ';
#define bug(a) cout << #a << " == " << a << '\n';

void Solution(int T) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int base = (1LL << 31) - 1;
    for (auto [x, y] : mp) {
        int invx = x ^ base;
        if (mp.count(invx)) {
            if (mp[x] < mp[invx]) {
                mp[x] = 0;
            } else {
                mp[invx] = 0;
            }
        }
    }
    int ans = 0;
    for (auto& [x, y] : mp) ans += y;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}