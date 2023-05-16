#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL palindrome(LL half) {
    LL ans = half;
    while (half) {
        ans = ans * 10 + half % 10;
        half /= 10;
    }
    return ans;
}
LL getYear(LL date) {
    return date / 10000;
}
LL getMonth(LL date) {
    return date % 10000 / 100;
}
LL getDay(LL date) {
    return date % 100;
}
bool judgeDate(LL date, LL st, LL ed) {
    vector<LL> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date / 10000 % 400 == 0 || (date / 10000 % 4 == 0 && date / 10000 % 100 != 0)) {
        months[2] = 29;
    }
    if (getYear(date) < getYear(st) || getYear(date) > getYear(ed)) {
        return false;
    }
    if (getMonth(date) < 1 || getMonth(date) > 12) {
        return false;
    }
    if (getYear(date) == getYear(st) && getMonth(date) < getMonth(st)) {
        return false;
    }
    if (getYear(date) == getYear(ed) && getMonth(date) > getMonth(ed)) {
        return false;
    }
    if (getDay(date) <= 0 || months[getMonth(date)] < getDay(date)) {
        return false;
    }
    if (getYear(date) == getYear(st) && getMonth(date) == getMonth(st) && getDay(date) < getDay(st)) {
        return false;
    }
    if (getYear(date) == getYear(ed) && getMonth(date) == getMonth(ed) && getDay(date) > getDay(ed)) {
        return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL st;
    LL ed;
    LL ans = 0;
    cin >> st >> ed;
    for (LL i = st / 10000; i <= ed / 10000; ++i) {
        LL tmp = palindrome(i);
        ans += judgeDate(tmp, st, ed);
    }
    cout << ans << '\n';
}
