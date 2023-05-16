#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> ori;
    string tmp;
    getline(cin, tmp);
    while (tmp != "EOF") {
        ori.emplace_back(tmp);
        getline(cin, tmp);
    }
    vector<string> txt;
    getline(cin, tmp);
    while (tmp != "EOF") {
        txt.emplace_back(tmp);
        getline(cin, tmp);
    }
    LL id;
    double ans = 0;
    for (LL i = 0, _ = min(ori.size(), txt.size()); i < _; ++i) {
        tmp = "";
        for (LL j = 0; j < txt[i].size(); ++j) {
            if (txt[i][j] == '<') {
                if (tmp != "") {
                    tmp.pop_back();
                }
                continue;
            }
            tmp.push_back(txt[i][j]);
        }
        txt[i] = tmp;
        tmp = "";
        for (LL j = 0; j < ori[i].size(); ++j) {
            if (ori[i][j] == '<') {
                if (tmp != "") {
                    tmp.pop_back();
                }
                continue;
            }
            tmp.push_back(ori[i][j]);
        }
        ori[i] = tmp;
        id = 0;
        while (id < txt[i].size() && id < ori[i].size()) {
            if (txt[i][id] == ori[i][id]) {
                ans += 1;
            }
            ++id;
        }
    }
    LL time;
    cin >> time;
    cout << int(ans * 60.0 / double(time) + 0.5) << '\n';
}
