#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    LL w;
    LL n;
    cin >> w >> n;
    vector<LL> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    sort(p.begin(), p.end());
    int l = 0;
    int r = p.size() - 1;
    int res = 0;
    while (l <= r) {
        if (l == r) {
            res++;
            break;
        }
        if (p[r] > w) {
            r--;
            continue;
        }
        if (p[r] + p[l] > w) {
            r--;
            res++;
            continue;
        }
        l++;
        r--;
        res++;
    }
    cout << res << '\n';
}
