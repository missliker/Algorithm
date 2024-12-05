#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;
    string ans = string("");
    for (int i = 0; i < s.size();) {
        int j = i;
        while (j < s.size() and s[j] == s[i]) j++;
        ans += char('0' + j - i);
        ans += s[i];
        i = j;
    }
    cout << ans << '\n';

    return 0;
}