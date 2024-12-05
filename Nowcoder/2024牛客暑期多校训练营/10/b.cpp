#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, q;
    cin >> n >> q;

    map<string, string> dic;
    for (int i = 1; i <= n; i++) {
        string data, name;
        cin >> data >> name;
        name.pop_back();
        dic[name] = data;
    }

    while (q--) {
        string name;
        cin >> name;

        if (name.find('.') == string::npos) {
            cout << dic[name] << '\n';
            continue;
        }

        pair<pair<int, double>, pair<pair<double, double>, int>> fuck;
        pair<pair<int, int>, double> aks;

        auto dfs = [&](auto self, string name, string data) -> void {
            if (name.find('.') == string::npos) {
                if (name == "first") {
                    data = data.substr(5, data.rfind(',') - 5);
                } else {
                    data = data.substr(5);
                    int l = 0, p;
                    for (p = 0; p < data.size(); p++) {
                        if (data[p] == 'p') {
                            l++;
                        } else if (data[p] == '>') {
                            l--;
                        }
                        if (l == 0) break;
                    }
                    data = data.substr(p + 2);
                    data.pop_back();
                }
                cout << data << '\n';
                return;
            }

            string pre = name.substr(0, name.find('.'));
            name = name.substr(name.find('.') + 1);
            cout << "pre: " << pre << endl;
            cout << "name: " << name << endl;
            cout << "data: " << data << endl;
            if (pre == "first") {
                data = data.substr(5, data.rfind(',') - 5);
                self(self, name, data);
            } else {
                data = data.substr(5);
                int l = 0, p;
                for (p = 0; p < data.size(); p++) {
                    if (data[p] == 'p') {
                        l++;
                    } else if (data[p] == '>') {
                        l--;
                    }
                    if (l == 0) break;
                }
                data = data.substr(p + 2);
                data.pop_back();
                self(self, name, data);
            }
        };
        string data = dic[name.substr(0, name.find('.'))];
        name = name.substr(name.find('.') + 1);

        dfs(dfs, name, data);

        // if (name.find('.') == string::npos) {
        // 	cout << dic[name] << endl;
        // } else {
        // 	auto pre = name.substr(0, name.find('.'));
        // 	auto suf = name.substr(name.find('.') + 1);
        // 	cout << pre << ' ' << suf << endl;
        // 	auto data = dic[pre];
        // 	data = data.substr(data.find('<') + 1);
        // 	cout << data << endl;
        // }
    }

    return 0;
}