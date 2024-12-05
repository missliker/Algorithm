#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, K;
    string S;
    cin >> N >> K >> S;
    ranges::sort(S);
    set<string> st;
    do {
        bool ok = true;
        for (int i = 0; i <= N - K; i++) {
            auto T = S.substr(i, K);
            auto RT = T;
            ranges::reverse(RT);
            if (RT == T) {
                ok = false;
                break;
            }
        }
        if (ok) st.insert(S);
    } while (next_permutation(S.begin(), S.end()));
    cout << st.size() << '\n';

    return 0;
}