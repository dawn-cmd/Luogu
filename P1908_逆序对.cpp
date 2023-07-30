#include <bits/stdc++.h>
#define LL long long
using namespace std;
class BIT {
private:
    vector<LL> tree;
    LL lowbit(LL id) { return id & -id; }

public:
    BIT(LL n) {
        tree.clear();
        tree.resize(n * 2);
    }
    void add(LL pos, const LL &val) {
        for (; pos < tree.size(); pos += lowbit(pos)) tree[pos] += val;
    }
    LL sum(LL pos) {
        LL res = 0;
        for (; pos; pos -= lowbit(pos)) res += tree[pos];
        return res;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n;
    cin >> n;
    vector<LL> tmp(n);
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> tmp[i];
        a[i] = tmp[i];
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    unordered_map<LL, LL> id;
    for (int i = 1; i <= tmp.size(); ++i) id[tmp[i - 1]] = i;
    LL ans = 0;
    BIT prefixSum(n);
    for (int i = n - 1; i >= 0; --i) {
        ans += prefixSum.sum(id[a[i]] - 1);
        prefixSum.add(id[a[i]], 1);
    }
    cout << ans << '\n';
}
