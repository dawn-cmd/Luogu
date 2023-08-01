#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL id(LL len, LL n) {
    if (n > len) n = id(len << 1, n);
    if (n > (len >> 1)) {
        return ((n - (len >> 1) - 1 > 0) ? (n - (len >> 1) - 1) : (len >> 1));
    }
    return n;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    LL n;
    cin >> s >> n;
    cout << s[id(s.size() << 1, n) - 1] << '\n';
}
