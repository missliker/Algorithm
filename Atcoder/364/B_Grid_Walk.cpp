#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int H, W, Si, Sj;
    cin >> H >> W >> Si >> Sj;
    Si--, Sj--;
    string C[H];
    for (auto& i : C) cin >> i;
    string X;
    cin >> X;
    for (auto& i : X) {
        if (i == 'U') {
            if (Si > 0 and C[Si - 1][Sj] == '.') Si--;
        } else if (i == 'D') {
            if (Si < H - 1 and C[Si + 1][Sj] == '.') Si++;
        } else if (i == 'L') {
            if (Sj > 0 and C[Si][Sj - 1] == '.') Sj--;
        } else if (i == 'R') {
            if (Sj < W - 1 and C[Si][Sj + 1] == '.') Sj++;
        }
    }
    cout << Si + 1 << ' ' << Sj + 1 << '\n';

    return 0;
}