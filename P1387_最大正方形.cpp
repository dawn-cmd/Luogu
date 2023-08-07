#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; ++i)
        for (int j = 1; j < m + 1; ++j)
            cin >> g[i][j];
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; ++i)
        for (int j = 1; j < m + 1; ++j)
            prefix[i][j] = g[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    for (int res = max(n, m); res > 0; --res) {
        for (int i = 1; i + res - 1 < n + 1; ++i) {
            for (int j = 1; j + res - 1 < m + 1; ++j) {
                if (prefix[i + res - 1][j + res - 1] - prefix[i + res - 1][j - 1] - prefix[i - 1][j + res - 1] + prefix[i - 1][j - 1] == res * res) {
                    cout << res << '\n';
                    return 0;
                }
            }
        }
    }
    cout << 1 << '\n';
}
