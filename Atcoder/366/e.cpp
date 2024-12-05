#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, D;
    cin >> N >> D;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    ranges::sort(X);
    ranges::sort(Y);
    vector<i64> Sx(N + 1), Sy(N + 1);
    for (int i = 1; i <= N; i++) {
        Sx[i] = Sx[i - 1] + X[i - 1];
        Sy[i] = Sy[i - 1] + Y[i - 1];
    }

    vector<i64> cntx, cnty;
    for (i64 i = -2E6; i <= 2E6; i++) {
        i64 a = ranges::lower_bound(X, i) - begin(X);
        i64 Dx = Sx[N] - Sx[a] * 2LL + (2LL * a - N) * i;
        if (Dx <= D) {
            cntx.emplace_back(Dx);
        }
        i64 b = ranges::lower_bound(Y, i) - begin(Y);
        i64 Dy = Sy[N] - Sy[b] * 2LL + (2LL * b - N) * i;
        if (Dy <= D) {
            cnty.emplace_back(Dy);
        }
    }

    i64 ans = 0;
    ranges::sort(cnty);
    for (auto& x : cntx) {
        i64 cnt = ranges::upper_bound(cnty, D - x) - begin(cnty);
        ans += cnt;
    }
    cout << ans << '\n';

    return 0;
}