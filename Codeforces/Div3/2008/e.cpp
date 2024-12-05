#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Solution(int T) {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> odd, eve;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            odd[s[i]]++;
        } else {
            eve[s[i]]++;
        }
    }
    int ans = n;
    if (n % 2 == 0) {
        for (char c = 'a'; c <= 'z'; c++) {
            for (char d = 'a'; d <= 'z'; d++) {
                ans = min(ans, n - odd[c] - eve[d]);
            }
        }
    } else {
        vector vodd(n, vector<int>(26, 0));
        vector veve(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                vodd[i][s[i] - 'a']++;
            } else {
                veve[i][s[i] - 'a']++;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                vodd[i][j] += vodd[i - 1][j];
                veve[i][j] += veve[i - 1][j];
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            for (char d = 'a'; d <= 'z'; d++) {
                ans = min(ans, n - (veve[n - 1][c - 'a'] - veve[0][c - 'a']) - (vodd[n - 1][d - 'a'] - vodd[0][d - 'a']));
            }
        }
        for (int i = 1; i < n; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                for (char d = 'a'; d <= 'z'; d++) {
                    ans = min(ans, n - (vodd[i - 1][c - 'a'] + veve[n - 1][c - 'a'] - veve[i][c - 'a']) - (veve[i - 1][d - 'a'] + vodd[n - 1][d - 'a'] - vodd[i][d - 'a']));
                }
            }
        }
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