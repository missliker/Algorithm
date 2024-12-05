#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S;
    getline(cin, S);
    map<char, char> dic, redic;
    char tot = 'a';
    for (auto& c : S) {
        if (c >= 'a' and c <= 'z') {
            c = toupper(c);
            if (!dic.count(c)) dic[c] = tot++;
        } else if (c >= 'A' and c <= 'Z') {
            if (!dic.count(c)) dic[c] = tot++;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!dic.count(c)) dic[c] = tot++;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        char small = dic[c];
        redic[small] = c;
    }

    string op;
    while (cin >> op) {
        cin.get();
        if (op == "END") {
            cout << "Thanks for using goodbye!";
            break;
        }
        string T;
        getline(cin, T);
        if (op == "encryption") {
            for (auto& c : T) {
                if (c >= 'a' and c <= 'z') c = redic[c];
                cout << c;
            }
            cout << '\n';
        } else {
            for (auto& c : T) {
                if (c >= 'A' and c <= 'Z') c = dic[c];
                cout << c;
            }
            cout << '\n';
        }
    }

    return 0;
}