/**
 * @file P1126_机器人搬重物.cpp
 * @author HuaiYuan Jing (ls.hyjing@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define LL long long
#define mp(a, b) make_pair(a, b)
using namespace std;
// Define an item representing a robot state in the grid
class item {
public:
    int pos; // position of robot in 1D
    int d;   // current direction robot is facing
    int step;// number of steps taken so far
    item(int pos, int d, int step) {
        this->pos = pos;
        this->d = d;
        this->step = step;
    }
};
// BFS function to find the shortest path in the grid from start to end position
int bfs(const vector<vector<int>> &g, int start_x, int start_y, int start_d, int end_x, int end_y) {
    int n = g.size();
    int m = g[0].size();
    // Define directions: S (South), W (West), N (North), E (East)
    vector<int> dirs{1, 0, -1, 0, 1};
    // Utility function to convert 2D position to 1D
    auto encode = [m](const int &x, const int &y) { return x * m + y; };
    // Utility function to convert 1D position back to 2D
    auto decode = [m](const int &id) { return mp(id / m, id % m); };
    queue<item> q;
    q.push(item(encode(start_x, start_y), start_d, 0));
    // Set to keep track of visited states
    set<pair<int, int>> vis;
    // Start BFS
    while (!q.empty()) {
        int cur_x = decode(q.front().pos).first;
        int cur_y = decode(q.front().pos).second;
        int cur_d = q.front().d;
        int cur_step = q.front().step;
        // If current position is the end position, return steps taken
        if (cur_x == end_x && cur_y == end_y) return cur_step;
        q.pop();
        // Continue if current state is already visited
        if (vis.find(mp(encode(cur_x, cur_y), cur_d)) != vis.end()) continue;
        vis.emplace(encode(cur_x, cur_y), cur_d);
        // Turn right and push new state
        q.emplace(item(encode(cur_x, cur_y), (cur_d + 1) % 4, cur_step + 1));
        // Turn left and push new state
        q.emplace(item(encode(cur_x, cur_y), (cur_d + 3) % 4, cur_step + 1));
        // Check and add all possible forward moves (1, 2, 3 steps)
        for (int i = 1; i <= 3; ++i) {
            int nxt_x = cur_x + i * dirs[cur_d];
            int nxt_y = cur_y + i * dirs[cur_d + 1];
            // Skip if next state is out of bounds or has an obstacle
            if (nxt_x <= 0 || nxt_x >= n - 1 || nxt_y <= 0 || nxt_y >= m - 1) continue;
            if (g[nxt_x][nxt_y]) break;
            q.emplace(item(encode(nxt_x, nxt_y), cur_d, cur_step + 1));
        }
    }
    // Return -1 if destination is unreachable
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;// n = rows, m = columns of the grid
    cin >> n >> m;
    // Grid representing the storage room; 0 = empty, 1 = obstacle
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp;
            cin >> tmp;
            // Mark all the adjacent cells of an obstacle as 1 (since robot is larger than a single grid cell)
            if (!tmp) continue;
            g[i][j] = g[i][j + 1] = g[i + 1][j] = g[i + 1][j + 1] = 1;
        }
    }
    // Input starting and ending positions
    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;
    string d;// Initial direction of the robot
    cin >> d;
    // Convert string direction to corresponding integer value
    int start_d = d == "S" ? 0 : (d == "W" ? 1 : (d == "N" ? 2 : 3));
    // Print the minimum time required
    cout << bfs(g, start_x, start_y, start_d, end_x, end_y) << '\n';
}
