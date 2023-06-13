#include <bits/stdc++.h>
#define LL long long
using namespace std;
class player {
    public:
        int id;
        int score;
        int w;
};
bool cmp(const player& p1, const player& p2) {
    if (p1.score != p2.score) {
        return p1.score > p2.score;
    }
    return p1.id < p2.id;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n;
    LL r;
    LL q;
    cin >> n >> r >> q;
    vector<player> players(n * 2);
    for (int i = 0; i < n * 2; ++i) {
        players[i].id = i + 1;
        cin >> players[i].score;
    }
    for (int i = 0; i < n * 2; ++i) {
        cin >> players[i].w;
    }
    sort(players.begin(), players.end(), cmp);
    for (int i = 0; i < r; ++i) {
        vector<player> winners;
        vector<player> losers;
        for (int j = 0; j < n; ++j) {
            // cout << players[j * 2].id << ' ' << players[j * 2 + 1].id << ' ';
            if (players[j * 2].w > players[j * 2 + 1].w) {
                players[j * 2].score++;
                winners.emplace_back(players[j * 2]);
                losers.emplace_back(players[j * 2 + 1]);
            }
            else {
                players[j * 2 + 1].score++;
                winners.emplace_back(players[j * 2 + 1]);
                losers.emplace_back(players[j * 2]);
            }
        }
        // cout << endl;
        merge(winners.begin(), winners.end(), losers.begin(), losers.end(), players.begin(), cmp);
    }
    cout << players[q - 1].id << '\n';
}
