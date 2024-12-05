#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, m;
    cin >> n >> m;
    if (m >= n - 2) {
        cout << "-1\n";
        return;
    }

    vector<int> a(n);
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

    int res = 0;
    while (res != m) {
        res = 0;
        random_shuffle(a.begin(), a.end());
        for (int i = 0; i + 2 < n; i++) {
            int x = a[i], y = a[i + 1], z = a[i + 2];
            bool ok = check(x, y, z);
            res += ok;
        }
        if (res == m) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == n - 1];
            }
            break;
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