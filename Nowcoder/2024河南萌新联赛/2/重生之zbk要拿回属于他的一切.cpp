#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    string s, t = "chuan";
    cin >> n >> s;

    int it = s.find(t);
    int ans = 0;
    while (it != string::npos) {
        it = s.find(t, it + t.size());
        ans++;
    }
    cout << ans << '\n';

    return 0;
}