#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    string S[N];
    int M = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        M = max<int>(M, S[i].size());
    }

    string T[M];
    for (int i = 0; i < M; i++) {
    	for (int j = N - 1; j >= 0; j--) {
    		if (S[j].size() <= i) {
    			T[i] += '*';
    		} else {
    			T[i] += S[j][i];
    		}
    	}
    }
    for (int i = 0; i < M; i++) {
    	while (T[i].back() == '*') T[i].pop_back();
    	cout << T[i] << '\n';
    }

    return 0;
}