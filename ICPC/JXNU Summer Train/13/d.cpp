#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 1E9;

void Solution(int T) {
    int n, ahp, bhp;
    cin >> n >> ahp >> bhp;
    int ade = 0, bde = 0;
    vector<int> atk, btk;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            ade++;
        } else {
            atk.emplace_back(x);
        }
    }
    sort(atk.begin(), atk.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            bde++;
        } else {
            btk.emplace_back(x);
        }
    }

    /*

















    */
    sort(btk.begin(), btk.end());

    while (ade > 0 and not btk.empty()) {
        ade--;
        btk.pop_back();
    }

    while (bde > 0 and ade > 0) {
        bde--;
        ade--;
    }

    while (bde > 0 and not atk.empty()) {
        bde--;
        atk.pop_back();
    }

    for (int i = 0; i < min(atk.size(), btk.size()); i++) {
        ahp -= btk[i];
        bhp -= atk[i];
        if (bhp <= 0) {
            cout << "yes\n";
            return;
        }
        if (ahp <= 0) {
            cout << "no\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}