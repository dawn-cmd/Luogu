#include <bits/stdc++.h>
#define LL long long
using namespace std;

// Function to read input text and store it in a vector of strings
void getText(vector<string>& target) {
    string tmp;
    getline(cin, tmp); // Read a line of text
    while (tmp != "EOF") { // Continue until "EOF" is encountered
        target.emplace_back(tmp); // Add the line to the vector
        getline(cin, tmp); // Read the next line
    }
}

// Function to remove the last character if it is '<' from a given string
string removeBack(const string& s) {
    string ans = "";
    for (auto c: s) {
        if (c == '<' && ans != "") { // If the character is '<' and the result string is not empty
            ans.pop_back(); // Remove the last character
            continue;
        }
        ans.push_back(c); // Add the character to the result string
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> ori; // Original text
    getText(ori); // Read the original text

    vector<string> txt; // Text to compare
    getText(txt); // Read the text to compare

    LL id;
    double ans = 0;
    for (LL i = 0, _ = min(ori.size(), txt.size()); i < _; ++i) {
        ori[i] = removeBack(ori[i]); // Remove the last character if it is '<' from the original text line
        txt[i] = removeBack(txt[i]); // Remove the last character if it is '<' from the text to compare line
        id = 0;
        while (id < txt[i].size() && id < ori[i].size()) {
            if (txt[i][id] == ori[i][id]) { // If the characters at the same position are the same
                ans += 1; // Increment the count
            }
            ++id; // Move to the next position
        }
    }

    LL time;
    cin >> time; // Read the time value

    cout << int(ans * 60.0 / double(time) + 0.5) << '\n'; // Calculate and print the result

    return 0;
}
