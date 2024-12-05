#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    string S, F;
    cin >> S >> F;

    map<char, vector<int>> dic;
    for (int i = 0; i < S.size(); i++) dic[S[i]].emplace_back(i);

    int ans = S.size(), l = 0;
    for (auto bg : dic[F.front()]) {
        int lst = bg;
        bool ok = true;
        for (int i = 1; i < F.size(); i++) {
            auto it = ranges::upper_bound(dic[F[i]], lst);
            if (it == dic[F[i]].end()) {
                ok = false;
                break;
            }
            lst = *it;
        }
        if (not ok) break;
        if (lst - bg + 1 < ans) {
            ans = lst - bg + 1;
            l = bg;
        }
    }
    cout << S.substr(l, ans) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}