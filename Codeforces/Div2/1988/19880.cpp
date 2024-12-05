#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

void Solution(int T) {
    int n, k;
    cin >> n >> k;
    multiset<int> st;
    st.insert(n);
    int ans = 0;
    while (st.size()) {
        int x = *st.begin();
        st.erase(st.begin());
        
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}