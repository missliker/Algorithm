#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<int, int>;

void Solution(int T) {
    int n, k;
    cin >> n >> k;
    vector<Pair> v(n);
    priority_queue<Pair, vector<Pair>, greater<Pair>> p;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        p.emplace(min(v[i].first, v[i].second), i);
    }
    i64 ans = 0, score = 0;
    while (not p.empty()) {
        auto [x, i] = p.top();
        p.pop();
        // if (x == 0) continue;
        ans += x;
        score++;
        // cout << "score: " << score << endl;
        if (score >= k) break;
        if (x == v[i].first) {
            v[i].second--;
            if (v[i].second == 0) {
                ans += v[i].second;
                score++;
                if (score >= k) break;
            } else {
                p.emplace(min(x, v[i].second), i);
            }
        } else {
            v[i].first--;
            if (v[i].first == 0) {
                ans += v[i].first;
                score++;
                if (score >= k) break;
            } else {
                p.emplace(min(x, v[i].first), i);
            }
        }
        for (auto& [a, b] : v) {
            cout << a << ' ' << b << endl;
        }
        cout << "score: " << score << endl << "ans: " << ans << endl << endl;
        if (score >= k) break;
    }
    if (score >= k) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}