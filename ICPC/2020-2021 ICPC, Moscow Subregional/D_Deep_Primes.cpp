#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

// bool isPrime(int num) {
//     if (num < 2) {
//         return false;
//     }
//     for (int i = 2; i * i <= num; ++i) {
//         if (num % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// bool isDeepPrime(int num) {
//     string strNum = std::to_string(num);
//     for (int sz = 1; sz <= strNum.size(); ++sz) {
//         for (int l = 0; l + sz - 1 < strNum.size(); ++l) {
//             int r = l + sz - 1;
//             string subStr = strNum.substr(l, r - l + 1);
//             i64 subInt = stoi(subStr);
//             if (!isPrime(subInt))
//                 return false;
//         }
//     }
//     return true;
// }

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    i64 l, r;
    cin >> l >> r;
    vector<int> ans = {2, 3, 5, 7, 23, 37, 53, 73, 373};
    int cnt = 0;
    if (r <= 373) {
        for (auto x : ans) {
            if (x >= l and x <= r)
                cnt++;
        }
    } else if (l > 373) {
        cnt = 0;
    } else {
        auto it = lower_bound(ans.begin(), ans.end(), l) - ans.begin();
        for (int i = it; i < ans.size(); ++i) {
            if (ans[i] >= l and ans[i] <= r)
                cnt++;
        }
    }
    cout << cnt;

    return 0;
}