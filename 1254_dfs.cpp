class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        /*
            1、并查集
            2、深搜（从边界出发深搜把0置为1）
        */
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 0) {
                dfs(grid, i, m, n);
            }
            if (grid[m - 1][i] == 0) {
                dfs(grid, (m - 1) * n + i, m, n);
            }
        }
        for (int i = 0; i < m - 1; i++) {
            if (grid[i][0] == 0) {
                dfs(grid, i * n, m, n);
            }
            if (grid[i][n - 1] == 0) {
                dfs(grid, i * n + n -1, m, n);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i * n + j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid, int index, int m, int n) {
        int i = index / n;
        int j = index - i * n;
        grid[i][j] = 1;
        if (i != 0 && grid[i - 1][j] == 0) {
            dfs(grid, index - n, m, n);
        }
        if (i != m - 1 && grid[i + 1][j] == 0) {
            dfs(grid, index + n, m, n);
        }
        if (j != 0 && grid[i][j - 1] == 0) {
            dfs(grid, index - 1, m, n);
        }
        if (j != n - 1 && grid[i][j + 1] == 0) {
            dfs(grid, index + 1, m, n);
        }
    }
};
