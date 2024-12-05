#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n = 1010;
    string s[n];
    int pos = 0;
    while (cin >> s[pos])
        pos += 1;
    int l = stoi("20", 0, 16), r = stoi("7f", 0, 16);
    vector<int> a(pos);
    for (int i = 0; i < pos; ++i) {
        a[i] = stoi(s[i], 0, 16);
    }

    if (a[0] == 0) {
        cout << "Both\n";
        return 0;
    }
    bool pascal = true, c = false;
    for (int i = 0; i < pos; ++i) {
        if (a[i] == 0) {
            c = true;
            break;
        }
        if (a[i] < l or a[i] > r) {
            c = false;
            break;
        }
    }
    int sz = a[0];
    for (int i = 1; i <= sz; ++i) {
        if (i == pos) {
            pascal = false;
            break;
        }
        if (a[i] < l or a[i] > r)
            pascal = false;
    }
    if (!c and !pascal) {
        cout << "None\n";
    } else if (c and pascal) {
        cout << "Both\n";
    } else if (c and !pascal) {
        cout << "C\n";
    } else if (!c and pascal) {
        cout << "Pascal\n";
    }

    return 0;
}