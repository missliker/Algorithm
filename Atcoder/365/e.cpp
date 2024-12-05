#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<int> A(N + 1);
    i64 ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        ans -= A[i];
    }

    for (int k = 0; k < 30; k++) {
        int cnt[2] = {1, 0}, z = 0;
        for (int i = 1; i <= N; i++) {
            int x = A[i] >> k & 1;
            z ^= x;
            ans += (1LL << k) * cnt[z ^ 1];
            cnt[z]++;
        }
    }
    cout << ans << '\n';

    return 0;
}