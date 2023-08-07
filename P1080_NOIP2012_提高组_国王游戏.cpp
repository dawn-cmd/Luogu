#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    LL king_l, king_r;
    cin >> king_l >> king_r;
    vector<vector<LL>> hands(n, vector<LL>(2, 0));
    for (int i = 0; i < n; ++i) cin >> hands[i][0] >> hands[i][1];
    sort(hands.begin(), hands.end(), [](const vector<LL> &a, const vector<LL> &b) {
        double tmpa = (double) a[0] / (double) a[1];
        double tmpb = (double) b[0] / (double) b[1];
        return tmpa == tmpb ? a[1] < b[1] : tmpa > tmpb;
    });
    LL cur_l = king_l;
    LL res = -1;
    for (int i = 0; i < n; ++i) {
        res = max(res, cur_l / hands[i][1]);
        cur_l *= hands[i][0];
    }
    cout << res << '\n';
}
