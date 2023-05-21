#include <bits/stdc++.h>
#define LL long long
using namespace std;

// 3D array to store computed values
LL h[21][21][21];

// Recursive function to compute the value of w(a, b, c)
LL f(const LL &a, const LL &b, const LL &c) {
    // Base case: if any of the input values is less than or equal to 0, return 1
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    // If any of the input values is greater than 20, compute w(20, 20, 20) instead
    if (a > 20 || b > 20 || c > 20) {
        return f(20, 20, 20);
    }
    // If the value has already been computed, return it from the array
    if (h[a][b][c] != 0x3f3f3f3f) {
        return h[a][b][c];
    }
    // Compute the value of w(a, b, c) using the recurrence relation
    if (a < b && b < c) {
        h[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
        return h[a][b][c];
    }
    h[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
    return h[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Initialize the 3D array with a large value
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 21; ++j) {
            for (int k = 0; k < 21; ++k) {
                h[i][j][k] = 0x3f3f3f3f;
            }
        }
    }

    LL a;
    LL b;
    LL c;
    while (1) {
        // Read input values for a, b, and c
        cin >> a >> b >> c;
        // If the input values are -1, terminate the program
        if (a == -1 && b == -1 && c == -1) {
            return 0;
        }
        // Compute and print the value of w(a, b, c)
        cout << "w(" << a << ", " << b << ", " << c << ") = " << f(a, b, c) << '\n';
    }
}
