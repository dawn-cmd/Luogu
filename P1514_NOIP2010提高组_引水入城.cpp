/**
 * @file P1514_NOIP2010提高组_引水入城.cpp
 * @author HuaiYuan Jing (ls.hyjing@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define LL long long
#define mp(a, b) make_pair(a, b)
using namespace std;

// Representing the altitude of each city.
vector<vector<int>> height;

// Class representing the range for which water can be provided from a particular city.
class item {
public:
    int l;// left boundary of the range
    int r;// right boundary of the range
};

vector<vector<item>> range;// 2D array storing the range for each city.
set<pair<int, int>> vis;   // Used to track visited cities during DFS.

// List of directions for moving in the 2D grid.
vector<int> dir{1, 0, -1, 0, 1};

// Depth First Search to determine the range of cities a water facility can cover.
void dfs(int x, int y) {
    // If the city is already visited, return.
    if (vis.find(mp(x, y)) != vis.end()) return;

    vis.emplace(x, y);

    // If the city is adjacent to the desert.
    if (x == height.size() - 1) {
        range[x][y].l = y;
        range[x][y].r = y;
    } else {
        range[x][y].l = 0x3f3f3f3f;
        range[x][y].r = -0x3f3f3f3f;
    }

    // Traverse through all neighboring cities.
    for (int i = 0, nx, ny; i < 4; ++i) {
        nx = x + dir[i];
        ny = y + dir[i + 1];

        // Check for out of bounds or if the neighboring city is at a higher altitude.
        if (nx < 0 || nx >= height.size() || ny < 0 || ny >= height[0].size() || height[nx][ny] >= height[x][y]) continue;

        dfs(nx, ny);// Recursive DFS call.

        // Update the range based on neighboring cities' range.
        range[x][y].l = min(range[x][y].l, range[nx][ny].l);
        range[x][y].r = max(range[x][y].r, range[nx][ny].r);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    height = vector<vector<int>>(n, vector<int>(m, 0));
    range = vector<vector<item>>(n, vector<item>(m));

    // Input height of each city.
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> height[i][j];

    // Start DFS from cities adjacent to the lake (first row).
    for (int i = 0; i < m; ++i) dfs(0, i);

    // Calculate the number of cities adjacent to the desert that haven't been visited.
    int left_cities = 0;
    for (int i = 0; i < m; ++i) left_cities += vis.find(mp(n - 1, i)) == vis.end();

    // If there are any such cities, it's not possible to provide water to all cities adjacent to the desert.
    if (left_cities) {
        cout << 0 << '\n'
             << left_cities << '\n';
        return 0;
    }

    // Determine the minimum number of water reservoirs needed to cover all cities.
    int left_bound = 0;
    int res = 0;
    while (left_bound < m) {
        int max_right_bound = 0;
        for (int i = 0; i < m; ++i) {
            if (range[0][i].l > left_bound) continue;
            max_right_bound = max(max_right_bound, range[0][i].r);
        }
        ++res;
        left_bound = max_right_bound + 1;
    }

    cout << 1 << '\n'
         << res << '\n';
}
