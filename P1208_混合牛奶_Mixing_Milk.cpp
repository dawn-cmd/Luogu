#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    int m;
    cin >> n >> m;
    vector<pair<int, int>> milks;
    for (int i = 0, tmpp, tmpq; i < m; ++i) {
        cin >> tmpp >> tmpq;
        milks.emplace_back(tmpp, tmpq);
    }
    sort(milks.begin(), milks.end());
    long long res = 0;
    for (int i = 0; i < m && n; ++i) {
        res += milks[i].first * min(milks[i].second, n);
        n = max(0, n - milks[i].second);
    }
    cout << res << '\n';
}
