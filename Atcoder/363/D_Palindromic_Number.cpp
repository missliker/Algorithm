#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 N;
    cin >> N;
    if (N <= 10) {
        cout << N - 1 << '\n';
        return 0;
    }
    int B = 37;
    vector<i64> s(B);
    s[1] = 10;
    for (int i = 2; i < B; i++) {
        int k = (i + 1) / 2;
        s[i] = 9LL * pow(10LL, k - 1);
        s[i] += s[i - 1];
        // cerr << i << ' ' << s[i] << endl;
    }
    int k = 0;
    for (int i = 1; i < B; i++) {
        if (s[i] >= N) {
            k = i;
            break;
        }
    }
    // cerr << "k : " << k << endl;
    string ans = string("");
    if (k & 1) {
        N -= s[k - 1];
        // cout << N << endl;
        N += pow(10LL, (k + 1) / 2 - 1) - 1;
        // cout << N << endl;
        string L = to_string(N), R = L.substr(0, L.size() - 1);
        ranges::reverse(R);
        ans = L + R;
    } else {
        N -= s[k - 1];
        // cout << N << endl;
        N += pow(10LL, (k + 1) / 2 - 1) - 1;
        // cout << N << endl;
        string L = to_string(N), R = L;
        ranges::reverse(R);
        ans = L + R;
    }
    cout << ans << '\n';

    return 0;
}