#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    int s = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        s += A;
        q.push(A);
    }
    int ans = 0;
    while (s < 4.5 * N) {
        ans++;
        s -= q.top();
        q.pop();
        s += 5;
        q.push(5);
    }
    cout << ans << '\n';

    return 0;
}