#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> prefix(n);
    prefix[0] = nums[0] % 7;
    map<int, int> h;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        prefix[i] = (prefix[i - 1] + nums[i]) % 7;
        if (prefix[i] == 0) {
            ans = max(ans, i + 1);
            continue;
        }
        if (h.find(prefix[i]) != h.end()) continue;
        h[prefix[i]] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (prefix[i] == 0) continue;
        ans = max(i - h[prefix[i]], ans);
    }
    cout << ans << '\n';
}
