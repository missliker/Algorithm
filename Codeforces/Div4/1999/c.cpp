#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, s, m;
    cin >> n >> s >> m;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            if (l[i] - r[i - 1] >= s) {
                cout << "YES\n";
                return;
            }
        } else {
            if (l[i] >= s) {
                cout << "YES\n";
                return;
            }
        }
    }
    if (m - r.back() >= s) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}