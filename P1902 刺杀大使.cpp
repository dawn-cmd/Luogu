#include<bits/stdc++.h>
#define mp(a, b) make_pair(a, b)
using namespace std;
bool bfs(const int &limit, const vector<vector<int>> &dmg) {
    vector<vector<int>> h(dmg.size());
    for (int i = 0; i < dmg.size(); ++i) {
        h[i] = vector<int>(dmg[i].size());
        for (int j = 0; j < h[i].size(); ++j) {
            h[i][j] = 0;
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < dmg[0].size(); ++i) {
        q.push(mp(0, i));
        h[0][i] = 1;
    }
    vector<vector<int>> ds{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
        auto x = q.front().first;
        auto y = q.front().second;
        q.pop();
        for (auto d: ds) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (!(0 <= nx && nx < dmg.size() && 0 <= ny && ny < dmg[0].size() && h[nx][ny] == 0 && dmg[nx][ny] <= limit)) {
                continue;
            }
            q.push(mp(nx, ny));
            h[nx][ny] = 1;
            if (nx == dmg.size() - 1) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> dmg(n);
    for (int i = 0; i < n; ++i) {
        dmg[i] = vector<int>(m);
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> dmg[i][j];
            r = max(r, dmg[i][j]);
        }
    }
    int l = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        // cout << mid 
        if (!bfs(mid, dmg)) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
