#include <bits/stdc++.h>
#define LL long long
using namespace std;
void dfs(int cur, const vector<LL> &fa, vector<vector<LL>> &sons, const vector<LL> &w, vector<LL> &res) {
    if (sons[cur].size() == 0) {
        res[cur] = w[cur];
        return;
    }
    for (const auto &son: sons[cur]) dfs(son, fa, sons, w, res);
    sort(sons[cur].begin(), sons[cur].end(), [res, w](const LL &x, const LL &y) {
        return res[x] - w[x] > res[y] - w[y];
    });
    LL maxn = res[sons[cur][0]];
    LL sumn = w[sons[cur][0]];
    for (int i = 1; i < sons[cur].size(); ++i) {
        maxn = max(maxn, sumn + res[sons[cur][i]]);
        sumn += w[sons[cur][i]];
    }
    res[cur] = max(maxn, sumn + w[cur]);
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<LL> fa(n);
    vector<vector<LL>> sons(n);
    fa[0] = -1;
    for (LL i = 1; i < n; ++i) {
        cin >> fa[i];
        fa[i]--;
        sons[fa[i]].emplace_back(i);
    }
    vector<LL> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    vector<LL> res(n, 0);
    dfs(0, fa, sons, w, res);
    for (const auto &item: res) cout << item << ' ';
    cout << '\n';
}
