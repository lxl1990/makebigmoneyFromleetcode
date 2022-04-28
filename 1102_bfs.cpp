/*
    先正向遍历一遍，打上一圈标识，只能根据上、左方向更新；
    然后再遍历一遍check，不一致的深搜更新
    超时
*/
// class Solution {
// // int minVal = 1<<31;
// // unordered_map<int, int> cache_map;
// vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// public:
//     int maximumMinimumPath(vector<vector<int>>& grid) {
//         int m = grid.size();
//         if (m == 0) return 0;
//         int n = grid[0].size();
//         if (n == 0) return 0;
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         dp[m - 1][n - 1] = grid[m - 1][n - 1];
//         for (int row = 0; row < m; row++) {
//             for (int col = 0; col < n; col++) {
//                 int ret = -1;
//                 if (row != 0 && dp[row - 1][col] > ret) ret = dp[row - 1][col];
//                 if (col != 0 && dp[row][col - 1] > ret) ret = dp[row][col - 1];
//                 if (ret == -1 || ret > grid[row][col]) ret = grid[row][col];
//                 dp[row][col] = ret;
//                 // cout << "row: " << row << ", col: " << col << ", val: " << ret << endl;
//             }
//         }
//         cout << "first traverse end" << endl;
//         for (int row = 0; row < m; row++) {
//             for (int col = 0; col < n; col++) {
//                 int ret = -1;
//                 for (auto direction : directions) {
//                     int new_row = row + direction[0];
//                     int new_col = col + direction[1];
//                     if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
//                         ret = max(ret, dp[new_row][new_col]);
//                     }
//                 }
//                 ret = min(ret, grid[row][col]);
//                 if (dp[row][col] != ret) {
//                     vector<vector<int>> visited(m, vector<int>(n, 0));
//                     dp[row][col] = ret;
//                     cout << "second traverse,diff row: " << row << ", col: " << col << endl;
//                     dfs(grid, dp, visited, row, col, m, n);
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
//     void dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, vector<vector<int>>& visited, int row, int col, int m, int n) {
//         // cout << "dfs row: " << row << ", col: " << col << ", update val: " << dp[row][col] << endl;
//         if (visited[row][col] > 0) return;
//         visited[row][col] = 1;
//         for (auto direction : directions) {
//             int new_row = row + direction[0];
//             int new_col = col + direction[1];
//             if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
//                 int ret = min(grid[new_row][new_col], dp[row][col]);
//                 if (dp[new_row][new_col] < ret) {
//                     dp[new_row][new_col] = ret;
//                     dfs(grid, dp, visited, new_row, new_col, m, n);
//                 }
//             }
//         }
//         visited[row][col] = 2;
//     }
// };


/*
类prim算法
*/
// struct Node {
//     int x;
//     int y;
//     int score;
//     Node() : x(-1), y(-1), score(0){}
//     Node(int x, int y, int score) : x(x), y(y), score(score) {}
//     bool operator < (const Node& a) const {
//         return this->score < a.score;
//     }
// };

// class Solution {
// // int minVal = 1<<31;
// // unordered_map<int, int> cache_map;

// vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// public:
//     int maximumMinimumPath(vector<vector<int>>& grid) {
//         int m = grid.size();
//         if (m == 0) return 0;
//         int n = grid[0].size();
//         if (n == 0) return 0;
//         int ans = grid[0][0];
//         vector<vector<int>> visited(m, vector<int>(n, 0));
//         priority_queue<Node> que;
//         que.push(Node(0, 0, grid[0][0]));
//         visited[0][0] = 1;
//         while (!que.empty()) {
//             Node root = que.top();
//             que.pop();
//             ans = min(ans, root.score);
//             if (root.x == m - 1 && root.y == n - 1) return ans;
//             for (auto direction : directions) {
//                 int x = root.x + direction[0];
//                 int y = root.y + direction[1];
//                 if (x < 0 || x == m || y < 0 || y == n || visited[x][y] == 1) continue;
//                 que.push(Node(x, y, grid[x][y]));
//                 visited[x][y] = 1;
//             }
//         }
//         return ans;
//     }
// };

// typedef struct Node {
//     int x;
//     int y;
//     int score;
//     Node() : x(-1), y(-1), score(0){}
//     Node(int x, int y, int score) : x(x), y(y), score(score) {}
//     // bool operator < (const Node& a) const {
//     //     return this->score < a.score;
//     // }
// } *NodePtr;
// struct myComparator {
//     bool operator() (NodePtr n1, NodePtr n2) {
//         return n1->score < n2->score;
//     }
// };
// class Solution {
// // int minVal = 1<<31;
// // unordered_map<int, int> cache_map;
// public:
//     int maximumMinimumPath(vector<vector<int>>& grid) {
//         int m = grid.size();
//         if (m == 0) return 0;
//         int n = grid[0].size();
//         if (n == 0) return 0;
//         int ans = grid[0][0];
//         vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//         vector<vector<int>> visited(m, vector<int>(n, 0));
//         priority_queue<NodePtr, vector<NodePtr>, myComparator> que;
//         // Node* root = new Node(0, 0, grid[0][0]);
//         que.push(new Node(0, 0, grid[0][0]));
//         visited[0][0] = 1;
//         while (!que.empty()) {
//             NodePtr root = que.top();
//             que.pop();
//             ans = min(ans, root->score);
//             if (root->x == m - 1 && root->y == n - 1) return ans;
//             for (auto direction : directions) {
//                 int x = root->x + direction[0];
//                 int y = root->y + direction[1];
//                 if (x < 0 || x == m || y < 0 || y == n || visited[x][y] == 1) continue;
//                 que.push(new Node(x, y, grid[x][y]));
//                 visited[x][y] = 1;
//             }
//         }
//         return ans;
//     }
// };



/*
dfs + 二分查找
*/
class Solution {
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        int ans = min(grid[0][0], grid[m - 1][n - 1]);
        vector<int> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] < ans) {
                    points.emplace_back(grid[i][j]);
                }
            }
        }
        points.emplace_back(ans);
        sort(points.begin(), points.end());
        int len = points.size();
        int left = -1, right = len;
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            // cout << "check val:" << mid << ", " << points[mid] << endl;
            vector<vector<int>> visited(m, vector<int>(n, 0));
            if (dfs(grid, visited, 0, points[mid], m, n)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return points[left];
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int index, int val, int m, int n) {
        int row = index / n;
        int col = index - n * row;
        if (row == m - 1 && col == n - 1) return true;
        visited[row][col] = 1;
        for (auto direction : directions) {
            int new_row = row + direction[0];
            int new_col = col + direction[1];
            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
                if (visited[new_row][new_col] == 1 || grid[new_row][new_col] < val) continue;
                if (dfs(grid, visited, new_row * n + new_col, val, m, n)) return true;
            }
        }
        return false;
    }
};

