#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve(int T) {
    int n;
    cin >> n;
    vector<array<int, 3>> q(n);
    vector<int> v(4);
    for (int i = 0; i < n; i++) {
        int l, r, o;
        cin >> l >> r >> o;
        q.push_back({l, r, o});
    }
    bool ok = false;
    for (int i = 1; i <= 3; i++) {
        v[1] = i;
        for (int j = 1; j <= 3; j++) {
            v[2] = j;
            for (int k = 1; k <= 3; k++) {
                v[3] = k;
                bool f = true;
                for (auto [l, r, o] : q) {
                    if (o) {
                        if (v[l] >= v[r]) {
                            f = false;
                            break;
                        }
                    } else {
                        if (v[l] < v[r]) {
                            f = false;
                            break;
                        }
                    }
                }
                ok |= f;
            }
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}
