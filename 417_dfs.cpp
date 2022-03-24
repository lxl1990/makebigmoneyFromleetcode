class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*
            最复杂的方法就是对每个单元，上下左右遍历是否可以通过，只要左上 和 右下都可以通过就添加进结果；中间判断涉及递归判断，可以存下结果，每个节点结果均为2个方向（左下、右上）的标识
        */

        int m = heights.size();
        if (m == 0) return vector<vector<int>>();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        //up && down
        for (int i = 0; i < n; i++) {
            pacific[0][i] = 1;
            dfs(pacific, heights, i, m, n);
            atlantic[m - 1][i] = 1;
            dfs(atlantic, heights, (m - 1) * n + i, m, n);
        }
        //left && right
        for (int i = 0; i < m; i++) {
            pacific[i][0] = 1;
            dfs(pacific, heights, i * n, m, n);
            atlantic[i][n - 1] = 1;
            dfs(atlantic, heights, i * n + n - 1, m, n);
        }
        
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (pacific[i][j] == 1) {
        //             dfs(pacific, heights, i * n + j, m, n);
        //         }
        //         if (atlantic[i][j] == 1) {
        //             dfs(atlantic, heights, i * n + j, m, n);
        //         }
        //     }
        // }
        vector<vector<int>> ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ret.emplace_back(vector<int>{i, j});
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& pacificAtlantic, const vector<vector<int>>& heights, int index, int m, int n) {
        int i = index / n;
        int j = index - i * n;
        //上
        if (i != 0 && heights[i][j] <= heights[i - 1][j] && pacificAtlantic[i - 1][j] == 0) {        
            pacificAtlantic[i - 1][j] = 1;
            dfs(pacificAtlantic, heights, index - n, m, n);
        }
        //下
        if (i != m - 1 && heights[i][j] <= heights[i + 1][j] && pacificAtlantic[i + 1][j] == 0) {
            pacificAtlantic[i + 1][j] = 1;
            dfs(pacificAtlantic, heights, index + n, m, n);
        }
        //左
        if (j != 0 && heights[i][j] <= heights[i][j - 1] && pacificAtlantic[i][j - 1] == 0) {
            pacificAtlantic[i][j - 1] = 1;
            dfs(pacificAtlantic, heights, index - 1, m, n);
        }
        //右
        if (j != n - 1 && heights[i][j] <= heights[i][j + 1] && pacificAtlantic[i][j + 1] == 0) {
            pacificAtlantic[i][j + 1] = 1;
            dfs(pacificAtlantic, heights, index + 1, m, n);
        }
    }
};
