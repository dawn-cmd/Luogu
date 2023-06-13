#include <bits/stdc++.h>
using namespace std;
int main() {
    double a;
    double b;
    double c;
    double d;
    cin >> a >> b >> c >> d;
    auto f = [a, b, c, d](double x) -> double { return a * x * x * x + b * x * x + c * x + d; };
    vector<double> anss;
    for (double i = -100; i < 100; i += 1) {
        if (f(i) == 0) {
            anss.emplace_back(i);
            continue;
        }
        if (f(i) * f(i + 1) < 0) {
            double l = i;
            double r = i + 1;
            while (r - l >= 0.001) {
                double mid = (r + l) / 2;
                if (f(mid) * f(l) < 0) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            anss.emplace_back(l);
            if (anss.size() >= 3) {
                break;
            }
        }
    }
    if (f(100) == 0) {
        anss.emplace_back(100);
    }
    sort(anss.begin(), anss.end());
    for (auto ans: anss) {
        printf("%.2lf ", ans);
    }
    cout << '\n';
    return 0;
}
