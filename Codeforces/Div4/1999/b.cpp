#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int a[2], b[2];
    for (int i = 0; i < 2; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> b[i];
    }
    int x = 0, y = 0, ans = 0;
    for (int i = 0; i < 2; i++) {
        if (a[i] > b[i]) x++;
        else if (a[i] < b[i]) y++;
    }
    if (x > y) ans++;

    x = 0, y = 0;
    swap(b[0], b[1]);
    for (int i = 0; i < 2; i++) {
        if (a[i] > b[i]) x++;
        else if (a[i] < b[i]) y++;
    }
    if (x > y) ans++;

    x = 0, y = 0;
    swap(a[0], a[1]);
    for (int i = 0; i < 2; i++) {
        if (a[i] > b[i]) x++;
        else if (a[i] < b[i]) y++;
    }
    if (x > y) ans++;

    x = 0, y = 0;
    swap(b[0], b[1]);
    for (int i = 0; i < 2; i++) {
        if (a[i] > b[i]) x++;
        else if (a[i] < b[i]) y++;
    }
    if (x > y) ans++;

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}