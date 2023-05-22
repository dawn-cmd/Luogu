// Includes the header file which contains most commonly used libraries in C++
#include <bits/stdc++.h>

// Defines a long long data type as LL for easy access later
#define LL long long

// Includes the standard namespace to avoid writing std:: before every standard function or object
using namespace std;

// Defines a struct for person containing a string (name) and an integer (dir)
struct person {
    string name;
    int dir;
};

// Main function
int main() {
    // Optimizes input and output operations
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Declares two long long variables n and m
    LL n;
    LL m;

    // Takes input for the variables n and m
    cin >> n >> m;

    // Declares a vector of type person of size n
    vector<person> people(n);

    // Loop to take input for each person's direction and name
    for (int i = 0; i < n; ++i) {
        string name;
        int dir;
        cin >> dir >> name;
        people[i].dir = dir;
        people[i].name = name;
    }

    // Initializes the current person index as 0
    int cur = 0;

    // Loop to modify the current person index based on each of the next m operations
    for (int i = 0; i < m; ++i) {
        int dir;
        int steps;
        // Takes input for the direction and steps for the ith operation
        cin >> dir >> steps;
        // XOR operation between the input direction and the current person's direction
        dir ^= people[cur].dir;
        // Updating the current person index based on the XOR operation and steps
        cur += (dir == 1 ? 1 : -1) * steps;
        // Modifying the current person index to ensure it's within the valid range (0 to n-1)
        while (cur < 0) {
            cur += n;
        }
        cur %= n;
    }

    // Outputs the name of the current person after all m operations
    cout << people[cur].name << '\n';
}
