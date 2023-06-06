#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n;
    cin >> n;
    string st;
    getline(cin, st);
    map<string, int> scholarship;
    LL total_scholarship = 0;
    LL max_scholarship = 0;
    string max_student;
    for (int i = 0; i < n; ++i) {
        string name;
        int final_score;
        int class_score;
        string is_leader;
        string is_west;
        int essay_num;
        cin >> name >> final_score >> class_score >> is_leader >> is_west >> essay_num;
        scholarship[name] = 0;
        if (final_score > 80 && essay_num >= 1) {
            scholarship[name] += 8000;
        }
        if (final_score > 85 && class_score > 80) {
            scholarship[name] += 4000;
        }
        if (final_score > 90) {
            scholarship[name] += 2000;
        }
        if (final_score > 85 && is_west == "Y") {
            scholarship[name] += 1000;
        }
        if (final_score > 80 && is_leader == "Y") {
            scholarship[name] += 850;
        }
        if (scholarship[name] > max_scholarship) {
            max_scholarship = scholarship[name];
            max_student = name;
        }
        total_scholarship += scholarship[name];
    }
    cout << max_student << '\n'
         << max_scholarship << '\n'
         << total_scholarship << '\n';
}
