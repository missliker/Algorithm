#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s.size() == 5 and s[2] == s[4]) {
            set<char> st;
            for (int i = 0; i < 4; i++) st.insert(s[i]);
            if (st.size() == 4) {
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}