/*
    如果类似一维接雨水去做就掉进坑里面了
    类似dijkstra处理，使用最小堆
*/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m <= 2) return 0;
        int n = heightMap[0].size();
        if (n <= 2) return 0;

        auto myCmp = [](const pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        vector<int> visited(m * n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCmp)> pq(myCmp);
        //先加入边界
        for (int i = 0; i < m; i++) {
            pq.emplace(make_pair(i * n, heightMap[i][0]));
            // cout << "emplace: " << i * n << ", " << heightMap[i][0] << endl;
            pq.emplace(make_pair(i * n + n - 1, heightMap[i][n - 1]));
            // cout << "emplace: " << i * n + n - 1 << ", " << heightMap[i][n - 1] << endl;
            visited[i * n] = 1;
            visited[i * n + n - 1] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (visited[j] == 0) {
                // cout << "emplace: " << j << ", " << heightMap[0][j] << endl;
                pq.emplace(make_pair(j, heightMap[0][j]));
                visited[j] = 1;
            }
            if (visited[(m - 1) * n + j] == 0) {
                // cout << "emplace: " << (m - 1) * n + j << ", " << heightMap[m - 1][j] << endl;
                pq.emplace(make_pair((m - 1) * n + j, heightMap[m - 1][j]));
                visited[(m - 1) * n + j] = 1;
            }
        }
        //然后从最小的边界开始
        int dirs[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        int sum = 0;
        while (!pq.empty()) {
            auto curNode = pq.top();
            pq.pop();
            int curX = curNode.first / n;
            int curY = curNode.first - curX * n;
            // cout << "curNode.first: " << curNode.first << ",curX: " << curX << ", curY: " << curY << endl;
            for (int dir = 0; dir < 4; dir++) {
                int x = curX + dirs[dir][0];
                int y = curY + dirs[dir][1];
                // cout << "dir:" << dir << ", x:" << x << ", y:" << y << endl;
                if (x > 0 && x < m - 1 && y > 0 && y < n -1 && visited[x * n + y] == 0) {
                        if (heightMap[x][y] < curNode.second) {
                            sum += curNode.second - heightMap[x][y];
                        }
                        pq.emplace(make_pair(x * n + y, max(curNode.second, heightMap[x][y])));
                        // cout << "emplace: " << x * n + y << ", " << max(curNode.second, heightMap[x][y]) << endl;
                        visited[x * n + y] = 1;
                }
            }
        }
        
        return sum;
    }
};
