#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

typedef pair<i64, i64> PII;
#define x first
#define y second

#define deg(a) cerr << #a << " == " << a << " ";
#define bug(a) cerr << #a << " == " << a << "\n";

int main() {
    // cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    string AA, BB;
    map<string, PII> A, B;
    map<string, int> te;
    cin >> AA;
    map<PII, string> idx;
    int it = 0;
    for (int i = 0; i < 5; ++i) {
        string s;
        cin >> s;
        A[s].x = 0;
        A[s].y = 1;
        idx[{0, it}] = s;
        te[s] = 0;
        it++;
    }
    cin >> BB;
    te[BB] = 1;
    for (int i = 0; i < 5; ++i) {
        string s;
        cin >> s;
        B[s].x = 0;
        B[s].y = 1;
        idx[{1, it}] = s;
        te[s] = 1;
        it++;
    }
    int q;
    cin >> q;
    getchar();
    for (int i = 0; i < q; ++i) {
        string s;
        getline(cin, s);
        s += " ";
        vector<string> a;
        string tmp;
        tmp.clear();
        for (auto c : s) {
            if (c == ' ') {
                if (tmp.size())
                    a.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(c);
            }
        }
        // cout << s << endl;
        // cout << a.size() << endl;
        if (a.size() == 4) {
            string team = a[1], score = a[3];
            if (team == AA) {
                for (auto& [name, it] : A) {
                    if (it.y == 1)
                        it.x += (score.back() - '0');
                }
                for (auto& [name, it] : B) {
                    if (it.y == 1) {
                        it.x -= (score.back() - '0');
                    }
                }
            } else {
                for (auto& [name, it] : B) {
                    if (it.y == 1)
                        it.x += (score.back() - '0');
                }
                for (auto& [name, it] : A) {
                    if (it.y == 1)
                        it.x -= (score.back() - '0');
                }
            }
        } else {
            string x = a[1], y = a[3], z = a[5];
            int the = (x == BB);
            bool have = false;
            for (int j = 0; j < it; j++) {
                if (idx.count({the, j}) and idx[{the, j}] == z)
                    have = true;
            }
            if (!have) {
                idx[{the, it}] = z;
                te[z] = (x == AA ? 0 : 1);
                it++;
            }
            if (x == AA) {
                A[y].y = 2;
                A[z].y = 1;
            } else {
                B[y].y = 2;
                B[z].y = 1;
            }
        }
    }
    for (int i = 0; i <= 20; i++) {
        if (idx.count({0, i})) {
            if (A[idx[{0, i}]].y) {
                cout << idx[{0, i}] << " (" << AA << ") ";
                if (A[idx[{0, i}]].x > 0)
                    cout << "+";
                cout << A[idx[{0, i}]].x << "\n";
            }
        } else if (idx.count({1, i})) {
            if (B[idx[{1, i}]].y) {
                cout << idx[{1, i}] << " (" << BB << ") ";
                if (B[idx[{1, i}]].x > 0)
                    cout << "+";
                cout << B[idx[{1, i}]].x << "\n";
            }
        }
        // if (te[idx[i]] == 0) {
        //     if (A[idx[i]].y) {
        //         cout << idx[i] << "(" << AA << ") ";
        //         if (A[idx[i]].x > 0) cout << "+";
        //         cout << A[idx[i]].x << "\n";
        //     }
        // } else {
        //     if (B[idx[i]].y) {
        //         cout << idx[i] << "(" << BB << ") ";
        //         if (B[idx[i]].x > 0) cout << "+";
        //         cout << B[idx[i]].x << "\n";
        //     }
        // }
    }

    return 0;
}