#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.size(); i++) {
        ans += s[i];
        while (ans.size() >= 3 and ans.back() == ans.end()[-2] and ans.back() == ans.end()[-3]) {
            ans.pop_back();
            ans.pop_back();
            ans.pop_back();
        }
    }
    if (ans.empty()) ans = "NAN";
    cout << ans << '\n';

    return 0;
}