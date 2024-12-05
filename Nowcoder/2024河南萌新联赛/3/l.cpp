#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int m, n, q;
    cin >> m >> n >> q;
    map<string, string> dic;
    for (int i = 0; i < m; i++) {
        string l, r;
        cin >> l >> r;
        dic[r] = l;
    }

    map<string, map<string, set<string>>> ips;
    for (int i = 0; i < n; i++) {
    	string ip;
    	int k;
    	cin >> ip >> k;
    	for (int j = 0; j < k; j++) {
    		string user;
    		int t;
    		cin >> user >> t;
    		for (int l = 0; l < t; l++) {
    			string pub;
    			cin >> pub;
    			ips[ip][user].insert(pub);
    		}
    	}
    }

    while (q--) {
    	string user, ip, pri;
    	cin >> user >> ip >> pri;
    	string pub = dic[pri];
    	if (ips.count(ip) and ips[ip].count(user) and ips[ip][user].find(pub) != ips[ip][user].end()) {
    		cout << "Yes\n";
    	} else {
    		cout << "No\n";
    	}
    }

    return 0;
}