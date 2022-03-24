class Solution {
private:
    vector<vector<int>> ret;
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visted(m, vector<int>(n, 0));
        dfs(visted, grid, row, col, m, n);
        for (auto point : ret) {
            grid[point[0]][point[1]] = color;
        }
        return grid;
    }
    void dfs(vector<vector<int>>& visted, vector<vector<int>>& grid, int row, int col, int m, int n) {
        if (visted[row][col] == 1) return;
        int adjacent = 0;
        visted[row][col] = 1;
        if (row == 0 || grid[row - 1][col] != grid[row][col]) {
            adjacent++;
        } else {
            dfs(visted, grid, row - 1, col, m, n);
        }
        if (row == m - 1 || grid[row + 1][col] != grid[row][col]) {
            adjacent++;
        } else {
            dfs(visted, grid, row + 1, col, m, n);
        }
        if (col == 0 || grid[row][col - 1] != grid[row][col]) {
            adjacent++;
        } else {
            dfs(visted, grid, row, col - 1, m, n);
        }
        if (col == n - 1 || grid[row][col + 1] != grid[row][col]) {
            adjacent++;
        } else {
            dfs(visted, grid, row, col + 1, m, n);
        }
        // cout << "row: " << row << ", col: " << col << ", adjacent: " << adjacent << endl;
        if (adjacent != 0) ret.emplace_back(vector<int>{row, col});
    }
};

// typedef pair<int, int> pii;

// class Solution {
// public:
//     vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         vector<pii> borders;
//         int originalColor = grid[row][col];
//         visited[row][col] = true;
//         dfs(grid, row, col, visited, borders, originalColor);
//         for (auto & [x, y] : borders) {
//             grid[x][y] = color;
//         }
//         return grid;
//     }

//     void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>> & visited, vector<pii> & borders, int originalColor) {
//         int m = grid.size(), n = grid[0].size();
//         bool isBorder = false;
//         int direc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//         for (int i = 0; i < 4; i++) {
//             int nx = direc[i][0] + x, ny = direc[i][1] + y;
//             if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == originalColor)) {
//                 isBorder = true;
//             } else if (!visited[nx][ny]) {
//                 visited[nx][ny] = true;
//                 dfs(grid, nx, ny, visited, borders, originalColor);
//             }                
//         }
//         if (isBorder) {
//             borders.emplace_back(x, y);
//         }
//     }
// };

