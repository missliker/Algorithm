#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<i64> A(N);
    for (auto& x : A) cin >> x;
    set<int> D;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) D.insert(A[1] + i - A[0] - j);
    }
    auto B = A;
    int ans = N + 1;
    for (auto& d : D) {
        for (int i = -1; i <= 1; i++) {
            A = B;
            int res = (i != 0);
            A[0] += i;
            bool ok = true;
            for (int j = 1; j < N; j++) {
                if (A[j] - A[j - 1] == d) continue;
                if (A[j] - A[j - 1] == d - 1 or A[j] - A[j - 1] == d + 1) {
                    A[j] = A[j - 1] + d;
                    res++;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = min(ans, res);
        }
    }
    if (ans == N + 1) ans = -1;
    cout << ans << '\n';

    return 0;
}