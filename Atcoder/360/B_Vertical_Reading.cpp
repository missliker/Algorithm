#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define deg(a) cout << #a << " == " << a << ' ';
#define bug(a) cout << #a << " == " << a << '\n';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S, T;
    cin >> S >> T;
    for (int l = 1; l < S.size(); l++) {
        vector<string> v(l);
        for (int i = 0; i < S.size(); i++) v[i % l] += S[i];
        for (auto& s : v) {
            if (s == T) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";

    return 0;
}