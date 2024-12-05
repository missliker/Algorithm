#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    char d;
    cin >> n >> m >> d;
    vector<string> v(n);
    for (auto& s : v) cin >> s;
    for (auto& s : v) {
        for (auto& c : s) { c = '9' - c + '0'; }
    }
    if (d == 'S') {
        for (int i = 0; i < n / 2; i++) { swap(v[i], v[n - 1 - i]); }
        for (auto& s : v) reverse(s.begin(), s.end());
    }
    for (auto& s : v) cout << s << '\n';

    return 0;
}