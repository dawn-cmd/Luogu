#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    LL a1;
    LL a2;
    LL n;
    cin >> a1 >> a2 >> n;
    cout << (a1 + a1 + (a2 - a1) * (n - 1)) * n / 2 << '\n';
}
