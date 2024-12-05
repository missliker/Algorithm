#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    vector<int> a(3);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = a[1] - a[0] + a[2] - a[1];
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