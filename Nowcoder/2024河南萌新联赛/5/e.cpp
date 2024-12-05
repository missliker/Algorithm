#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    if (n < 7) {
        cout << "-1\n";
        return;
    }

    auto check = [&](int x) {
        if (x < 2) return false;
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    };

    for (int i = 2; i <= n; i++) {
        if (not check(i)) continue;
        for (int j = 2; j <= n - i; j++) {
            if (not check(j)) continue;
            if (not check(n - i - j)) continue;
            vector<int> ans{i, j, n - i - j};
            sort(ans.begin(), ans.end());
            for (int k = 0; k < 3; k++) {
                cout << ans[k] << " \n"[k == 2];
            }
            return;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}