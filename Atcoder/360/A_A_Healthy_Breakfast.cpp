#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S;
    cin >> S;
    auto R = S.find('R'), M = S.find('M');
    cout << (R < M ? "Yes" : "No") << '\n';

    return 0;
}