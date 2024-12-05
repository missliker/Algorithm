#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<i64> s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    string t;
    cin >> t;

    vector<int> R;
    for (int i = 0; i < n; i++) {
        if (t[i] == 'R') {
            R.emplace_back(i + 1);
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 'L') {
            if (not R.empty() and R.back() > i + 1) {
                ans += s[R.back()] - s[i];
                R.pop_back();
            } else {
                cout << ans << '\n';
                return;
            }
        }
    }
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