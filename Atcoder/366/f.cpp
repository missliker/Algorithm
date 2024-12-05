#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> id(N), real;
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
        if (A[i] == A[j]) return B[i] > B[j];
        return A[i] > A[j];
    });
    for (int i = 0; i < min({10, N, K}); i++) {
        real.emplace_back(id[i]);
    }

    sort(id.begin(), id.end(), [&](int i, int j) {
        if (B[i] == B[j]) return A[i] > A[j];
        return B[i] > B[j];
    });
    real.emplace_back(id.front());

    sort(real.begin(), real.end());
    real.erase(unique(real.begin(), real.end()), real.end());

    i64 ans = 1, now = 1;
    vector<int> p;
    auto dfs = [&](auto self, int u, int have) {
        if (u == real.size()) {
            if (have == K) {
                auto np = p;
                sort(np.begin(), np.end());
                do {
                    now = 1;
                    for (int i : np) {
                        now = now * A[i] + B[i];
                    }
                    ans = max(ans, now);
                } while (next_permutation(np.begin(), np.end()));
            }
            return;
        }

        self(self, u + 1, have);
        if (have < K) {
            p.emplace_back(real[u]);
            self(self, u + 1, have + 1);
            p.pop_back();
        }
    };
    dfs(dfs, 0, 0);
    cout << ans << '\n';

    return 0;
}