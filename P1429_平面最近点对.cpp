#include <bits/stdc++.h>
#define LL long long
using namespace std;
double dist(const pair<double, double> &a, const pair<double, double> &b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
double divide_and_conquer(const vector<pair<double, double>> &points, int l, int r) {
    if (r - l + 1 <= 1) return 0x3f3f3f3f;
    if (r - l + 1 == 2) return dist(points[l], points[r]);
    int mid = (l + r) >> 1;
    double dl = divide_and_conquer(points, l, mid);
    double dr = divide_and_conquer(points, mid + 1, r);
    double res = min(dl, dr);
    LL tmp = points[mid].first;
    vector<pair<LL, LL>> tmp_p;
    for (int i = l; i <= r; ++i) {
        if (abs(points[i].first - tmp) <= res) {
            tmp_p.emplace_back(points[i]);
        }
    }
    sort(tmp_p.begin(), tmp_p.end(), [](const pair<double, double> &a, const pair<double, double> &b) { return a.second < b.second; });
    for (int i = 0; i < tmp_p.size(); ++i) {
        for (int j = i + 1; j < tmp_p.size() && tmp_p[j].second - tmp_p[i].second <= res; ++j) {
            res = min(res, dist(tmp_p[i], tmp_p[j]));
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i) cin >> points[i].first >> points[i].second;
    sort(points.begin(), points.end());
    cout << fixed << setprecision(4) << divide_and_conquer(points, 0, points.size() - 1) << '\n';
}
