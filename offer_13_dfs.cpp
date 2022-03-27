class Solution {
public:
    int movingCount(int m, int n, int k) {
        /*
            从（0，0）开始出发，深搜可以到达多少格子，仅遍寻right down两个方向即可
        */
        int ret = 0;
        vector<int> visited(m * n, 0);
        stack<pair<int, int>> stk;
        stk.push(make_pair(0, 0));
        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            int index = cur.first, sum = cur.second;
            if (visited[index] != 0) continue;
            visited[index] = 1;
            ret++;
            int row = index / n;
            int col = index - row * n;
            // //up
            // if (row != 0) {
            //     if (row % 10 != 0) {
            //         stk.push(make_pair(index - n, sum - 1));
            //     } else if (sum + 8 <= k) {
            //         stk.push(make_pair(index - n, sum + 8));
            //     }
            // }
            //down
            if (row != m -1) {
                if (row % 10 == 9) {
                    stk.push(make_pair(index + n, sum - 8));
                } else if (sum < k) {
                    stk.push(make_pair(index + n, sum + 1));
                }
            }
            //left
            // if (col != 0) {
            //     if (col % 10 != 0) {
            //         stk.push(make_pair(index - 1, sum - 1));
            //     } else if (sum + 8 <= k) {
            //         stk.push(make_pair(index - 1, sum + 8));
            //     }
            // }
            //right
            if (col != n -1) {
                if (col % 10 == 9) {
                    stk.push(make_pair(index + 1, sum - 8));
                } else if (sum < k) {
                    stk.push(make_pair(index + 1, sum + 1));
                }
            }
        }
        return ret;
    }
};

// class Solution {
// public:
//     int movingCount(int m, int n, int k) {
//         vector<vector<bool>> visited(m, vector<bool>(n, 0));
//         return dfs(0, 0, 0, 0, visited, m, n, k);
//     }
// private:
//     int dfs(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k) {
//         if(i >= m || j >= n || k < si + sj || visited[i][j]) return 0;
//         visited[i][j] = true;
//         return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k) +
//                    dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
//     }
// };
