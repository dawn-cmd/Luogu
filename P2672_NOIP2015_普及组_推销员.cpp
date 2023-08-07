#include <bits/stdc++.h>
#define LL long long
using namespace std;
class customer {
public:
    LL s;
    LL a;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<customer> customers(n);
    for (int i = 0; i < n; ++i) cin >> customers[i].s;
    for (int i = 0; i < n; ++i) cin >> customers[i].a;

    sort(customers.begin(), customers.end(), [](const customer &a, const customer &b) { return a.a > b.a; });
    vector<LL> prefix_a(n);
    prefix_a[0] = customers[0].a;
    for (int i = 1; i < n; ++i) prefix_a[i] = prefix_a[i - 1] + customers[i].a;
    vector<LL> max_q(n);
    max_q[0] = customers[0].s * 2;
    for (int i = 1; i < n; ++i) max_q[i] = max(max_q[i - 1], customers[i].s * 2);
    vector<LL> max_h(n);
    max_h[n - 1] = customers[n - 1].s * 2 + customers[n - 1].a;
    for (int i = n - 2; i >= 0; --i) max_h[i] = max(max_h[i + 1], customers[i].s * 2 + customers[i].a);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << max(prefix_a[i] + max_q[i], max_h[i]) << '\n';
            continue;
        }
        cout << max(prefix_a[i] + max_q[i], prefix_a[i - 1] + max_h[i]) << '\n';
    }
}
