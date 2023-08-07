#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> relate(n, vector<int>(n, 0));
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int val;
            cin >> val;
            relate[i][j] = val;
            relate[j][i] = val;
        }
    }
    int my_choice = -1;
    int ai_choice = -1;
    int largest_snd = -1;
    for (int j = 0; j < n; ++j) {
        int largest = -1;
        int largest_id = -1;
        int snd = -1;
        int snd_id = -1;
        for (int k = 0; k < n; ++k) {
            if (relate[j][k] > largest) {
                snd = largest;
                snd_id = largest_id;
                largest = relate[j][k];
                largest_id = k;
                continue;
            }
            if (relate[j][k] > snd) {
                snd = relate[j][k];
                snd_id = k;
            }
        }
        if (snd > largest_snd) {
            largest_snd = snd;
            my_choice = j;
            ai_choice = largest_id;
        }
    }
    cout << 1 << '\n'
         << largest_snd << '\n';
}
