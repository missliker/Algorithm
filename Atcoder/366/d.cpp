#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int M = 110;
int A[M][M][M];
i64 S[M][M][M];

// S(X, Y, Z) = a(X, Y, Z)
// +S(X, Y, Z - 1) + S(X, Y - 1, Z) + S(X - 1, Y, Z)
// -S(X, Y - 1, Z - 1) - S(X - 1, Y, Z - 1) - S(X - 1, Y - 1, Z)
// +S(X - 1, Y - 1, Z - 1)

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                cin >> A[i][j][k];
                S[i][j][k] = S[i][j][k - 1] + S[i][j - 1][k] + S[i - 1][j][k] - S[i][j - 1][k - 1] - S[i - 1][j][k - 1] - S[i - 1][j - 1][k] + S[i - 1][j - 1][k - 1] + A[i][j][k];
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int Lx, Rx, Ly, Ry, Lz, Rz;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        i64 ans = S[Rx][Ry][Rz] - (S[Rx][Ry][Lz - 1] + S[Rx][Ly - 1][Rz] + S[Lx - 1][Ry][Rz] - S[Rx][Ly - 1][Lz - 1] - S[Lx - 1][Ry][Lz - 1] - S[Lx - 1][Ly - 1][Rz] + S[Lx - 1][Ly - 1][Lz - 1]);
        cout << ans << '\n';
    }

    return 0;
}