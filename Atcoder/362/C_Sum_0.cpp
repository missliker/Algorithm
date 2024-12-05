#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<i64> L(N), R(N);
    for (int i = 0; i < N; i++) cin >> L[i] >> R[i];
    i64 sum = 0;
    for (int i = 0; i < N; i++) sum += L[i];
    if (sum > 0) {
        cout << "No\n";
        return 0;
    }
    sum = 0;
    vector<i64> ans(N);
    for (int i = 0; i < N; i++) {
        sum += R[i];
        ans[i] = R[i];
    }
    if (sum < 0) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (sum > 0) {
            if (sum >= R[i] - L[i]) {
                ans[i] = L[i];
                sum -= R[i] - L[i];
            } else {
                ans[i] -= sum;
                sum = 0;
            }
        }
        if (sum == 0) break;
    }
    if (sum != 0) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (auto& i : ans) cout << i << ' ';

    return 0;
}