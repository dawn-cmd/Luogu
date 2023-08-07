#include <bits/stdc++.h>
#define LL long long
using namespace std;
class Item {
public:
    LL a;
    LL b;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        LL n;
        cin >> n;
        vector<Item> people(n);
        for (int i = 0; i < n; ++i) cin >> people[i].a >> people[i].b;
        sort(people.begin(), people.end(), [](const Item &x, const Item &y) {
            int dx = x.a <= x.b ? -1 : 1;
            int dy = y.a <= y.b ? -1 : 1;
            if (dx != dy) return dx < dy;
            else if (dx == -1)
                return x.a < y.a;
            else
                return x.b > y.b;
        });
        LL sum_a = people[0].a;
        LL c = people[0].a + people[0].b;
        for (int i = 1; i < n; ++i) {
            sum_a += people[i].a;
            c = max(c, sum_a) + people[i].b;
        }
        cout << c << '\n';
    }
}
