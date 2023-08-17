#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> g(5010, vector<int>(5010, 0));
    for (int i = 0, x, y, v; i < n; ++i) {
        cin >> x >> y >> v;
        g[x + 1][y + 1] += v;
    }
    for (int i = 1; i < 5010; ++i) {
        for (int j = 1; j < 5010; ++j) {
            g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i + m - 1 < 5010; ++i) {
        for (int j = 1; j + m - 1 < 5010; ++j) {
            ans = max(ans, g[i + m - 1][j + m - 1] - g[i - 1][j + m - 1] - g[i + m - 1][j - 1] + g[i - 1][j - 1]);
        }
    }
    cout << ans << '\n';
}
