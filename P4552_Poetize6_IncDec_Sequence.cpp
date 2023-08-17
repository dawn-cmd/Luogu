#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    LL pos = 0;
    LL neg = 0;
    for (int i = 1; i < n; ++i) {
        LL tmp = a[i] - a[i - 1];
        if (tmp > 0) pos += tmp;
        if (tmp < 0) neg -= tmp;
    }
    cout << max(pos, neg) << '\n'
         << abs(pos - neg) + 1 << '\n';
}
