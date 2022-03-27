// class Solution {
// public:
//     vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
//         int m = board.size();
//         if (m == 0) return board;
//         int n = board[0].size();
//         int row = click[0], col = click[1];
//         if (board[row][col] == 'M') {
//             board[row][col] = 'X';
//             return board;
//         }
//         vector<int> visted(m * n, 0);
//         dfs(board, visted, row * n + col, m, n);
//         return board;
//     }
//     void dfs(vector<vector<char>>& board, vector<int>& visted, int index, int m, int n) {
//         if (visted[index] == 1) return;
//         int row = index / n;
//         int col = index - row * n;
//         visted[index] = 1;
//         if (board[row][col] == 'M') return;
//         if (board[row][col] == 'E') {
//             int count_mines = 0;
//             //up-left
//             if (row != 0 && col != 0 && board[row - 1][col - 1] == 'M') {
//                 count_mines++;
//             }
//             //up
//             if (row != 0 && board[row - 1][col] == 'M') {
//                 count_mines++;
//             }
//             //up-right
//             if (row != 0 && col != n - 1 && board[row - 1][col + 1] == 'M') {
//                 count_mines++;
//             }
//             //left
//             if (col != 0 && board[row][col - 1] == 'M') {
//                 count_mines++;
//             }
//             //right
//             if (col != n - 1 && board[row][col + 1] == 'M') {
//                 count_mines++;
//             }
//             //down-left
//             if (row != m - 1 && col != 0 && board[row + 1][col - 1] == 'M') {
//                 count_mines++;
//             }
//             //down
//             if (row != m - 1 && board[row + 1][col] == 'M') {
//                 count_mines++;
//             }
//             //down-right
//             if (row != m - 1 && col != n - 1 && board[row + 1][col + 1] == 'M') {
//                 count_mines++;
//             }
//             if (count_mines == 0) {
//                 board[row][col] = 'B';
//                 if (row != 0 && col != 0) {
//                     dfs(board, visted, index - n - 1, m, n);
//                 }
//                 //up
//                 if (row != 0) {
//                     dfs(board, visted, index - n, m, n);
//                 }
//                 //up-right
//                 if (row != 0 && col != n - 1) {
//                     dfs(board, visted, index - n + 1, m, n);
//                 }
//                 //left
//                 if (col != 0) {
//                     dfs(board, visted, index - 1, m, n);
//                 }
//                 //right
//                 if (col != n - 1) {
//                     dfs(board, visted, index + 1, m, n);
//                 }
//                 //down-left
//                 if (row != m - 1 && col != 0) {
//                     dfs(board, visted, index + n - 1, m, n);
//                 }
//                 //down
//                 if (row != m - 1) {
//                     dfs(board, visted, index + n, m, n);
//                 }
//                 //down-right
//                 if (row != m - 1 && col != n - 1) {
//                     dfs(board, visted, index + n + 1, m, n);
//                 }
//             } else {
//                 board[row][col] = '0' + count_mines;
//             }
//         }
        
//     }
// };


class Solution {
public:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    void dfs(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
                continue;
            }
            // 不用判断 M，因为如果有 M 的话游戏已经结束了
            cnt += board[tx][ty] == 'M';
        }
        if (cnt > 0) {
            // 规则 3
            board[x][y] = cnt + '0';
        } else {
            // 规则 2
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                // 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
                    continue;
                }
                dfs(board, tx, ty);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            // 规则 1
            board[x][y] = 'X';
        } else {
            dfs(board, x, y);
        }
        return board;
    }
};
