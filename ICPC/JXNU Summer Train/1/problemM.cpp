#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 1E7 + 10;
vector<int> minp, primes, f(N);
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

void Solution(int T) {
    int n;
    cin >> n;
    cout << f[n] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    sieve(N);
    for (int i = 2; i < N; i++) {
        if (minp[i] == i) {
            f[i] = 1;
        } else {
            if (i & 1) {
                if (minp[i - 2] == i - 2) {
                    f[i] = 2;
                } else {
                    f[i] = 3;
                }
            } else {
                f[i] = 2;
            }
        }
    }
    for (int i = 3; i < N; i++) f[i] += f[i - 1];

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}