#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> minp, primes;
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
    int A, B;
    cin >> A >> B;
    int L = lower_bound(primes.begin(), primes.end(), A) - primes.begin();
    int R = lower_bound(primes.begin(), primes.end(), B) - primes.begin();
    if (minp[B] == B) R++;
    cout << R - L << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    sieve(1E7 + 10);
    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}