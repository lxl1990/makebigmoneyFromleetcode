// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         /*
//             遍历边界元素，深搜一遍，记录下所有“O”标志；
//             再便利一遍网格，保留标识位o，其他位置用X替换；
//         */
//         int m = board.size();
//         int n = board[0].size();
//         //上
//         for (int i = 0; i < n; i++) {
//             if (board[0][i] == 'X') continue;
//             dfs(board, i, m, n);
//         }
//         //下
//         for (int i = 0; i < n; i++) {
//             if (board[m - 1][i] == 'X') continue;
//             dfs(board, (m - 1) * n + i, m, n);
//         }
//         //左
//         for (int i = 0; i < m; i++) {
//             if (board[i][0] == 'X') continue;
//             dfs(board, i * n, m, n);
//         }
//         //右
//         for (int i = 0; i < m; i++) {
//             if (board[i][n - 1] == 'X') continue;
//             dfs(board, i * n + n - 1, m, n);
//         }
//         //便利一遍改写
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // cout << "i: " << i << ", j: " << j << ", val: " << board[i][j] <<endl;
//                 if (board[i][j] == '.') {
//                     board[i][j] = 'O';
//                 } else if (board[i][j] == 'O') {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
//     void dfs(vector<vector<char>>& board, int index, int m, int n) {
//         int row = index / n;
//         int col = index - row * n;
//         if (board[row][col] != 'O') return;
//         board[row][col] = '.';
//         if (row != 0) {
//             dfs(board, index - n, m, n);
//         }
//         if (row != m - 1) {
//             dfs(board, index + n, m, n);
//         }
//         if (col != 0) {
//             dfs(board, index - 1, m, n);
//         }
//         if (col != n - 1) {
//             dfs(board, index + 1, m, n);
//         }
//     }
// };



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /*
            并查集的方式
        */
        int m = board.size();
        int n = board[0].size();
        if (m * n == 0) return;
        //设置并查集，并设置一个边界节点
        vector<int> parents(m * n + 1, 0);
        vector<int> sizes(m * n + 1, 1);
        for (int i = 0; i < m * n + 1; i++) {
            parents[i] = i;
        }
        int dummy = m * n;
        //遍历所有节点，并将边界0 与 dummy 连通；
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') continue;
                if (i == 0 || i == m -1 || j == 0 || j == n - 1) {
                    union_all(parents, sizes, i * n + j, dummy);
                }
                //与上下左右连通
                if (i > 0 && board[i - 1][j] == 'O') {
                    union_all(parents, sizes, i * n + j, (i - 1) * n + j);
                }
                if (i < m -1 && board[i + 1][j] == 'O') {
                    union_all(parents, sizes, i * n + j, (i + 1) * n + j);
                }
                if (j > 0 && board[i][j - 1] == 'O') {
                    union_all(parents, sizes, i * n + j, i * n + j - 1);
                }
                if (j < n -1 && board[i][j + 1] == 'O') {
                    union_all(parents, sizes, i * n + j, i * n + j + 1);
                }
            }
        }
        //便利一遍改写
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << "i: " << i << ", j: " << j << ", val: " << board[i][j] <<endl;
                // cout << is_union(parents, i * n + j, dummy) << endl;
                if (board[i][j] == 'O' && !is_union(parents, i * n + j, dummy)) {
                    // cout << "i: " << i << ", j: " << j << ", val: " << board[i][j] <<endl;
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void union_all(vector<int>& parents, vector<int>& sizes, int i, int j) {
        int p1 = find(parents, i);
        int p2 = find(parents, j);
        if (sizes[p1] > sizes[p2]) {
            parents[p2] = p1;
        } else {
            parents[p1] = p2;
        }
    }
    int find(vector<int>& parents, int node) {
        while (parents[node] != node) {
            parents[node] = parents[parents[node]];
            node = parents[node];
        }
        return node;
    }
    bool is_union(vector<int>& parents, int node1, int node2) {
        int p1 = find(parents, node1);
        int p2 = find(parents, node2);
        return p1 == p2;
    }
};
