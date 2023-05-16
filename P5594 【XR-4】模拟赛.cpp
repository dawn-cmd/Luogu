#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector<unordered_set<int>> days(k);
    int tmp;
    while (n--) {
        for (int i = 0; i < m; ++i) {
            cin >> tmp;
            days[tmp - 1].insert(i);
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << days[i].size() << ' ';
    }
    cout << endl;
}
