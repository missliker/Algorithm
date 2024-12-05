#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n = 4;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    set<int> ans;
    do {
        vector<char> b;
        auto dfs = [&](auto self, int u) -> void {
            if (u == n) {
                vector<int> add = {a.front()};
                for (int i = 1; i < n; i++) {
                    if (b[i - 1] == '*') {
                        add.back() *= a[i];
                    } else {
                        add.emplace_back(a[i]);
                    }
                }
                vector<char> f;
                for (int i = 0; i < n - 1; i++) {
                    if (b[i] == '*') continue;
                    f.emplace_back(b[i]);
                }

                int res = add.front();
                for (int i = 1; i < add.size(); i++) {
                    if (f[i - 1] == '+') {
                        res += add[i];
                    } else {
                        res -= add[i];
                    }
                }
                ans.insert(res);
                return;
            }
            b.emplace_back('+');
            self(self, u + 1);
            b.pop_back();

            b.emplace_back('-');
            self(self, u + 1);
            b.pop_back();

            b.emplace_back('*');
            self(self, u + 1);
            b.pop_back();
        };
        dfs(dfs, 0);
    } while (next_permutation(a.begin(), a.end()));

    cout << ans.size() << '\n';

    return 0;
}