#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;

    iota(a.begin(), a.end(), 1);

    auto check = [&](int a, int b, int c) -> bool {
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        bool ok = true;
        do {
            if (v[0] + v[1] <= v[2]) {
                ok = false;
                break;
            }
            if (abs(v[0] - v[1]) >= v[2]) {
                ok = false;
                break;
            }
        } while (next_permutation(v.begin(), v.end()));
        return ok;
    };

    bool flag = false;
    do {
        int res = 0;
        for (int i = 0; i + 2 < n; i++) {
            int x = a[i], y = a[i + 1], z = a[i + 2];
            bool ok = check(x, y, z);
            res += ok;
        }
        if (res == m) {
            flag = true;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == n - 1];
            }
        }
    } while (next_permutation(a.begin(), a.end()));
    if (not flag) {
        cout << "-1\n";
    }

    return 0;
}