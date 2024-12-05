#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<int> A(N), W(N);
    vector<priority_queue<int, vector<int>, greater<int>>> B(N);
    for (auto& i : A) cin >> i, i--;
    for (auto& i : W) cin >> i;
    for (int i = 0; i < N; i++) { B[A[i]].push(W[i]); }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        while (B[i].size() > 1) {
            ans += B[i].top();
            B[i].pop();
        }
    }
    cout << ans << '\n';

    return 0;
}