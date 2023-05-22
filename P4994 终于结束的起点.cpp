#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL m;
    cin >> m;
    LL ans = 1;
    LL previous = 1;
    LL next = 1;
    while (!(previous % m == 0 && next % m == 1)) {
        next += previous;
        previous = next - previous;
        next %= m;
        previous %= m;
        ans++;
    }
    cout << ans << '\n';
}
