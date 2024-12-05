#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void g(vector<vector<double>>& matrix, vector<vector<double>>& temp, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p and col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double func(vector<vector<double>>& matrix, int n) {
    double det = 0;
    if (n == 1) return matrix[0][0];
    int sign = 1;
    vector<vector<double>> temp(n, vector<double>(n));

    for (int f = 0; f < n; f++) {
        g(matrix, temp, 0, f, n);
        det += sign * matrix[0][f] * func(temp, n - 1);
        sign = -sign;
    }

    return det;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector input(n, vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
        }
    }

    double ans = 1000000000.0;
    for (int i = 1; i <= max(n, m); i++) {
        vector matrix(i, vector<double>(i, 0));
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                if (j < n and k < m) matrix[j][k] = input[j][k];
            }
        }
        ans = min(ans, func(matrix, i));
    }
    cout << i64(ans) << '\n';

    return 0;
}