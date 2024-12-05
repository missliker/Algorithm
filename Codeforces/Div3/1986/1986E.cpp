#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    map<int, vector<int>> mp;
    i64 ans = 0;
    for (auto& i : a) mp[i % k].push_back(i);
    int cnt = 0;
    for (auto& [key, vec] : mp) {
        if (vec.size() & 1) {
            cnt++;
            if (n & 1) {
                if (cnt > 1) {
                    cout << "-1\n";
                    return;
                }
            } else {
                if (cnt) cout << "-1\n";
                return;
            }
            i64 res = 1E18 + 10;
            sort(vec.begin(), vec.end());
            priority_queue<int> q;
            for (int i = 0; i + 1 < vec.size(); i++) q.push(vec[i + 1] - vec[i]);
            vector<int> v;
            bool flag = false;
            for (int i = 0; i + 1 < vec.size(); i++) {
                if (vec[i + 1] - vec[i] == q.top()) {
                    if (flag) v.push_back(vec[i]);
                    else flag = true;
                }
                v.push_back(vec[i]);
            }
            for (int i = 0; i < vec.size(); i++) {
                auto v = vec;
                v.erase(lower_bound(v.begin(), v.end(), vec[i]));
                i64 tmp = 0;
                for (int j = 0; j < v.size(); j += 2) tmp += (v[j + 1] - v[j]) / k;
                res = min(res, tmp);
            }
            ans += res;
            continue;
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i += 2) ans += (vec[i + 1] - vec[i]) / k;
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