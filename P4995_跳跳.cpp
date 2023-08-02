#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    LL cur_h = 0;
    LL res = 0;
    vector<LL> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++i) {
        long long id = -1;
        long long maxn = -1;
        for (int j = 0; j < n; ++j) {
            if (vis[j]) continue;
            if ((cur_h - h[j]) * (cur_h - h[j]) <= maxn) continue;
            maxn = (cur_h - h[j]) * (cur_h - h[j]);
            id = j;
        }
        vis[id] = 1;
        res += maxn;
        cur_h = h[id];
    }
    cout << res << '\n';
}
