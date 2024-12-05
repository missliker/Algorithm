#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        auto t = s.substr(i, 17);
        if (count(t.begin(), t.end() + 5, t[0]) == 5 and count(t.begin() + 5, t.begin() + 12, t[6]) == 7 and count(t.begin() + 12, t.end(), t[16]) == 5) {
            cout << t << '\n';
            return 0;
        }
    }
    cout << "none\n";

    return 0;
}