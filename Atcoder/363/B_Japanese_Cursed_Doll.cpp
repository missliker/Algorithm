#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, T, P;
    cin >> N >> T >> P;
    vector<int> L(N);
    for (int& i : L) cin >> i;
    ranges::sort(L);
    for (int day = 0; day <= T; day++) {
        int cnt = end(L) - ranges::lower_bound(L, T - day);
        if (cnt >= P) {
            cout << day << '\n';
            return 0;
        }
    }

    return 0;
}