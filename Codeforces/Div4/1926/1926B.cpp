#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& s : v) cin >> s;
    int l = 0;
    for (int i = 0; i < n; i++) {
        int cnt = ranges::count(v[i], '1');
        l = max(l, cnt);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '0') continue;
            for (int x = i; x < i + l; x++) {
                for (int y = j; y < j + l; y++) {
                    if (v[x][y] == '0') {
                        cout << "TRIANGLE\n";
                        return;
                    }
                }
            }
            cout << "SQUARE\n";
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