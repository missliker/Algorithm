#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string a, b;
    cin >> a >> b;

    string aa = a, bb = b;
    int n = max(a.size(), b.size());
    if (a.size() < n) a += string(n - a.size(), '.');
    if (b.size() < n) b += string(n - b.size(), '.');
    char flag = '=';
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (a[i] == '.') {
            flag = '<';
            continue;
        }
        if (b[i] == '.') {
            flag = '>';
            continue;
        }
        if (a[i] > b[i]) flag = '>';
        else flag = '<';
        break;
    }
    a = aa, b = bb;
    cout << a << flag << b << '\n';

    return 0;
}