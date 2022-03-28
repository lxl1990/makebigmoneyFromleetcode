/*
类似1102，采用类prim方法
*/
// #include<cmath>

// struct Node {
//     int x;
//     int y;
//     int val;
//     Node(): x(-1), y(-1), val(-1) {}
//     Node(int x, int y, int val): x(x), y(y), val(val) {}
//     bool operator < (const Node& node) const {
//         return this->val > node.val;
//     }
// };
// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int ans = 0;
//         int m = heights.size();
//         if (m == 0) return ans;
//         int n = heights[0].size();
//         if (n == 0) return ans;
//         vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//         vector<int> visited(m * n, 0);
//         priority_queue<Node> queue;
//         queue.push(Node(0, 0, 0));
//         while(!queue.empty()) {
//             Node node = queue.top(); queue.pop();
//             if (visited[node.x * n + node.y] == 1) continue;
//             // cout << "pop: " << node.x << ", " << node.y << ", val: " << node.val << ", height: " << heights[node.x][node.y] << endl;
//             visited[node.x * n + node.y] = 1;
//             ans = max(ans, node.val);
//             if (node.x == m - 1 && node.y == n - 1) return ans;
//             for (auto direction: directions) {
//                 int x = node.x + direction[0];
//                 int y = node.y + direction[1];
//                 if (x < 0 || x == m || y < 0 || y == n) continue;
//                 queue.push(Node(x, y, abs(heights[x][y] - heights[node.x][node.y])));
//                 // cout << "push: " << x << ", " << y << ", val: " << abs(heights[x][y] - heights[node.x][node.y]) << ", height: " << heights[x][y] << endl;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        auto tupleCmp = [](const auto& e1, const auto& e2) {
            auto&& [x1, y1, d1] = e1;
            auto&& [x2, y2, d2] = e2;
            return d1 > d2;
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(tupleCmp)> q(tupleCmp);
        q.emplace(0, 0, 0);

        // vector<int> dist(m * n, INT_MAX);
        // dist[0] = 0;
        vector<int> seen(m * n);
        int ans = 0;
        while (!q.empty()) {
            auto [x, y, d] = q.top();
            q.pop();
            ans = max(ans, d);
            int id = x * n + y;
            if (seen[id]) {
                continue;
            }
            if (x == m - 1 && y == n - 1) {
                break;
            }
            seen[id] = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                // if (nx >= 0 && nx < m && ny >= 0 && ny < n && max(d, abs(heights[x][y] - heights[nx][ny])) < dist[nx * n + ny]) {
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    // dist[nx * n + ny] = max(d, abs(heights[x][y] - heights[nx][ny]));
                    q.emplace(nx, ny, abs(heights[x][y] - heights[nx][ny]));
                }
            }
        }
        
        // return dist[m * n - 1];
        return ans;
    }
};
