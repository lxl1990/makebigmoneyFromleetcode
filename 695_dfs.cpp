class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*
            遍历网格，从任意非0节点进入，深搜并重置0，累加面积，完全退出后重置返回结果
        */
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ans = 0;
                dfs(grid, m, n, i * n + j, ans);
                ret = max(ret, ans);
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& grid, int m, int n, int index, int& ans) {
        int row = index / n;
        int col = index % n;
        if (grid[row][col] != 1) return;
        // cout << ans;
        ans++;
        grid[row][col] = 0;
        if (row != 0) {
            dfs(grid, m, n, index - n, ans);
        }
        if (row != m - 1) {
            dfs(grid, m, n, index + n, ans);
        }
        if (col != 0) {
            dfs(grid, m, n, index - 1, ans);
        }
        if (col != n - 1) {
            dfs(grid, m, n, index + 1, ans);
        }
    }
};
