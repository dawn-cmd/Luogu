#include <bits/stdc++.h>
#define LL long long
#define mp(a, b) make_pair(a, b)
using namespace std;
int n, m;// row & colume
vector<vector<LL>> g;
int sx, sy, tx, ty;// start point & end point
vector<int> dirs{1, 0, -1, 0, 1};
map<pair<int, int>, LL> mem;
LL num_of_sol(int x, int y, int t) {      // dfs
    if (t == 0) return x == tx && y == ty;// find one way or not
    if (mem.find(mp(x * m + y, t)) != mem.end()) return mem[mp(x * m + y, t)];
    LL res = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dirs[i];
        int ny = y + dirs[i + 1];
        if (g[nx][ny]) continue;
        res += num_of_sol(nx, ny, t - 1);
    }
    mem[mp(x * m + y, t)] = res;
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;// time
    cin >> n >> m >> t;
    g = vector<vector<LL>>(n + 2, vector<LL>(m + 2, 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char tmp;
            cin >> tmp;
            g[i][j] = tmp == '.' ? 0 : 1;// transfer string graph to 01 graph
        }
    }
    cin >> sx >> sy >> tx >> ty;

    cout << num_of_sol(sx, sy, t) << '\n';
}
