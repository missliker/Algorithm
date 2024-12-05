// #include <bits/stdc++.h>
// using namespace std;
// using i64 = int64_t;
// using u64 = uint64_t;
// using ld = long double;
// constexpr ld Pi = 3.1415926535897932384626, esp = 1E-6;

// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     cout << fixed << setprecision(9);

//     int n;
//     cin >> n;
//     ld s = Pi / 2.0;
//     int cnt = 1;
//     vector<ld> ansx, ansy;
//     for (ld x = -1.0; x <= 1.0; x += 0.000001) {
//         ld l = 0.0, r = 1.0;
//         while (r - l > esp) {
//             ld mid = (l + r) / 2;
//             if (x * x + mid * mid <= 1) l = mid;
//             else r = mid;
//         }
//         ld y = r;
//         if (x < 0) {
//             ld Tan = y / (-x);
//             if (fabs(ld(atan(Tan)) * n - y * n - Pi * cnt) <= esp) {
//                 // cout << x << ' ' << y << '\n';
//                 ansx.push_back(x);
//                 ansy.push_back(y);
//                 cnt++;
//             }
//         } else {
//             ld Tan = y / x;
//             if (fabs(Pi * (n - cnt) - atan(Tan) * n - y * n) <= esp) {
//                 // cout << x << ' ' << y << '\n';
//                 ansx.push_back(x);
//                 ansy.push_back(y);
//                 cnt++;
//             }
//         }
//     }
//     reverse(ansx.begin(), ansx.end());
//     reverse(ansy.begin(), ansy.end());
//     for (int i = 0; i < ansx.size(); i++) cout << ansx[i] << ' ' << ansy[i] << '\n';

//     return 0;
// }