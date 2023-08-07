#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    for (int i = 1, x1, y1, x2, y2; i < m + 1; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2 + 1; ++j) {
            g[j][y1] += 1;
            if (y2 + 1 < n + 1) g[j][y2 + 1] -= 1;
        }
    }
    for (int i = 1, cur; i < n + 1; ++i) {
        cur = 0;
        for (int j = 1; j < n + 1; ++j) {
            cur += g[i][j];
            cout << cur << ' ';
        }
        cout << '\n';
    }
}
