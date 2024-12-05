#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

void Solution(int T) {
    i64 N;
    cin >> N;
    N++;

    i64 ans = 0;
    while (N) {
        ans += N / 5;
        N /= 5;
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