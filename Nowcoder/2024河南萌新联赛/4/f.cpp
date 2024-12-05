#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;
    vector<int> a;
    for (int i = 0; i < s.size();) {
    	int j = i, now = 0;
    	while (j < s.size() and s[j] != '+') {
    		now = now * 10 + int(s[j] - '0');
    		j++;
    	}
    	i = j + 1;
    	a.emplace_back(now);
    }
    sort(a.begin(), a.end(), greater<int>());
    i64 sum = 0;
    for (int i = 0; i < a.size(); i++) {
    	if (i) {
    		sum += a[i];
    		cout << '+' << a[i];
    	} else {
    		sum += a[i];
    		cout << a[i];
    	}
    }
    cout << '\n' << sum << '\n';

    return 0;
}