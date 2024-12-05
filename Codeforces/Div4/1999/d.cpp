#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (t[j] == s[i]) {
            j--;
        } else {
            if (s[i] == '?') {
                s[i] = t[j];
                j--;
            } else {
                continue;
            }
        }
        if (j == -1) break;
    }
    if (j == -1) {
        cout << "YES\n";
        for (auto& c : s) {
            if (c == '?') c = 'a';
        }
        cout << s << '\n';
    } else {
        cout << "NO\n";
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