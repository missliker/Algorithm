#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') continue;
        while (i < s.size() and s[i] == '1') i++;
        if (i < s.size()) ans++;
    }
    cout << ans << '\n';

    return 0;
}