#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<string> S(N);
    for (auto& i : S) cin >> i;

    for (int i = 0; i < N; i++) {
        if (S[i] == "sweet" and i >= 1 and S[i - 1] == "sweet" and i != N - 1) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}