#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T, vector<i64>& s) {
    int n;
    cin >> n;
    cout << s[n] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    auto f = [&](int x) {
        auto s = to_string(x);
        int res = 0;
        for (auto& i : s) res += i - '0';
        return res;
    };

    int N = 2E5;
    vector<i64> s(N + 1);
    for (int i = 1; i <= N; i++) s[i] = s[i - 1] + f(i);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T, s);

    return 0;
}