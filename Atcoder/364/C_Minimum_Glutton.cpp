#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 N, X, Y;
    cin >> N >> X >> Y;
    vector<i64> A(N), B(N);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        if (A[i] == A[j]) return B[i] > B[j];
        return A[i] > A[j];
    });
    i64 now = 0;
    int ans = N;
    for (int i = 0; i < N; i++) {
        now += A[p[i]];
        if (now > X) {
            ans = i + 1;
            break;
        }
    }
    sort(p.begin(), p.end(), [&](int i, int j) {
        if (B[i] == B[j]) return A[i] > A[j];
        return B[i] > B[j];
    });
    now = 0;
    for (int i = 0; i < N; i++) {
        now += B[p[i]];
        if (now > Y) {
            ans = min(ans, i + 1);
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}