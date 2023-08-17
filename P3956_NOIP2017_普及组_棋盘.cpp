#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<vector<int>> g;
vector<vector<int>> vis;
vector<vector<int>> mem;
void dfs(int x, int y, int cost, bool used_magic) {
    // cout << x << ' ' << y << ' ' << cost << ' ' << used_magic << '\n';
    if (vis[x][y]) return;
    if (cost >= mem[x][y] || cost > mem[g.size() - 1][g.size() - 1]) return;
    mem[x][y] = cost;
    vis[x][y] = 1;
    if (x == g.size() - 1 && y == g[0].size() - 1) {
        vis[x][y] = 0;
        return;
    }
    vector<int> dir{-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i];
        int ny = y + dir[i + 1];
        if (nx < 0 || nx >= g.size() || ny < 0 || ny >= g.size()) continue;
        if (vis[nx][ny]) continue;
        if (g[nx][ny] == g[x][y]) {
            dfs(nx, ny, cost, 0);
            continue;
        }
        if (g[nx][ny] != 0) {
            dfs(nx, ny, cost + 1, 0);
            continue;
        }
        if (used_magic) continue;
        g[nx][ny] = g[x][y];
        dfs(nx, ny, cost + 2, 1);
        g[nx][ny] = 0;
    }
    vis[x][y] = 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int m;
    int n;
    cin >> m >> n;
    g = vector<vector<int>>(m, vector<int>(m, 0));
    vis = vector<vector<int>>(m, vector<int>(m, 0));
    mem = vector<vector<int>>(m, vector<int>(m, 0x3f3f3f3f));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int x, y, c;
            cin >> x >> y >> c;
            g[x - 1][y - 1] = c + 1;
        }
    }
    dfs(0, 0, 0, 0);
    cout << (mem[m - 1][m - 1] == 0x3f3f3f3f ? -1 : mem[m - 1][m - 1]) << '\n';
}
