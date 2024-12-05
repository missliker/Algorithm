#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

map<i64, string> st;
void init() {
    st[0] = "Dragon";
    st[1] = "Snake";
    st[2] = "Horse";
    st[3] = "Goat";
    st[4] = "Monkey";
    st[5] = "Rooster";
    st[6] = "Dog";
    st[7] = "Pig";
    st[8] = "Rat";
    st[9] = "Ox";
    st[10] = "Tiger";
    st[11] = "Rabbit";
    st[12] = "Dragon";
}

void solve(int T) {
    i64 n;
    cin >> n;
    if (n < 0) {
        i64 cnt = abs(n) / 12 + 1;
        n += cnt * 12;
    }
    while (n < 0) n += 12;
    n %= 12;
    cout << st[n] << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int MAXT = 1;
    init();
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) solve(T);
    return 0;
}
