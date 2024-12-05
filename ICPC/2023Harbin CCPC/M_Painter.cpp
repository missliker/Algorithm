#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;
    struct info {
        string o;
        i64 xa, ya, xb, yb;
        char c;
    };
    vector<info> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i].o;
        if (q[i].o == "Circle") {
            cin >> q[i].xa >> q[i].ya >> q[i].xb >> q[i].c;
        } else if (q[i].o == "Rectangle") {
            cin >> q[i].xa >> q[i].ya >> q[i].xb >> q[i].yb >> q[i].c;
        } else {
            cin >> q[i].xa >> q[i].ya >> q[i].xb >> q[i].yb;
            for (int v = q[i].yb; v >= q[i].ya; v--) {
                for (int u = q[i].xa; u <= q[i].xb; u++) {
                    bool have = false;
                    for (int j = i - 1; j >= 0; j--) {
                        if (q[j].o == "Circle" and
                            (u - q[j].xa) * (u - q[j].xa) +
                                    (v - q[j].ya) * (v - q[j].ya) <=
                                q[j].xb * q[j].xb) {
                            cout << q[j].c;
                            have = true;
                            break;
                        } else if (q[j].o == "Rectangle" and u >= q[j].xa and
                                   u <= q[j].xb and v >= q[j].ya and
                                   v <= q[j].yb) {
                            cout << q[j].c;
                            have = true;
                            break;
                        }
                    }
                    if (!have) {
                        cout << '.';
                    }
                }
                cout << "\n";
            }
        }
    }

    return 0;
}