#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    string S;
    cin >> N >> S;
    S = " " + S;
    vector dp(N + 1, vector<int>(3, 0));
    for (int i = 1; i <= N; i++) {
    	if (S[i] == 'R') {
    		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
    		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
    	} else if (S[i] == 'S') {
    		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
    		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
    	} else {
    		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
    		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
    	}
    }
    cout << ranges::max(dp.back()) << '\n';

    return 0;
}