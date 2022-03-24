class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*
            二维遍历搜索匹配word第一个字符，如果匹配上，则转入dfs搜索确认
        */
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i * n + j, m, n, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int index, int m, int n, int len) {
        int row = index / n;
        int col = index - row * n;
        if (board[row][col] != word[len]) return false;
        if (len + 1 == word.size()) return true;
        board[row][col] = '.';
        //向上寻找
        if (row -1 >= 0 && dfs(board, word, index - n, m, n, len + 1)) return true;
        //向下寻找
        if (row + 1 < m && dfs(board, word, index + n, m, n, len + 1)) return true;
        //向左寻找
        if (col - 1 >= 0 && dfs(board, word, index - 1, m, n, len + 1)) return true;
        //向右寻找
        if (col + 1 < n && dfs(board, word, index + 1, m, n, len + 1)) return true;
        board[row][col] = word[len];
        return false;
    }
};
