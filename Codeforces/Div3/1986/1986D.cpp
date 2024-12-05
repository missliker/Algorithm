#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    string s;
    cin >> n >> s;

    auto calc = [&](vector<int>& v) {
        if (count(v.begin(), v.end(), 0)) return 0;
        int res = 0;
        for (auto& i : v) {
            if (i > 1) res += i;
        }
        return max(res, 1);
    };

    int ans = 1E9;
    for (int i = 0; i + 1 < n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                v.push_back(stoi(s.substr(j, 2), 0, 10));
                j++;
            } else {
                v.push_back(s[j] - '0');
            }
        }
        ans = min(ans, calc(v));
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