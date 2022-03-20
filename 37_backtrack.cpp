// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         if (board.size() != 9 || board[0].size() != 9) return;
//         backTrack(board, 0);
//     }
//     bool backTrack(vector<vector<char>>& board, int cur) {
//         if (cur == 81) return true;
//         int cur_row = cur / 9;
//         int cur_col = cur % 9;
//         // cout<< "cur_row:" << cur_row << ", cur_col: " << cur_col << ", val: " << board[cur_row][cur_col] << "\n";
//         if (board[cur_row][cur_col] == '.') {
//             for (int i = 1; i <= 9; i++) {
//                 board[cur_row][cur_col] = '0' + i;
//                 // cout<< "in for cur_row:" << cur_row << ", cur_col: " << cur_col << ", val: " << board[cur_row][cur_col] << "\n";
//                 if (isValid(board, cur_row, cur_col) && backTrack(board, cur + 1)) return true;
//                 board[cur_row][cur_col] = '.';
//             }
//         } else {
//             if (backTrack(board, cur + 1)) return true;
//         }
//         return false;
//     }
//     bool isValid(vector<vector<char>>& board, int cur_row, int cur_col) {
//         //row check
//         for (int i = 0; i < 9; i++) {
//             if (i == cur_col) continue;
//             if (board[cur_row][i] == board[cur_row][cur_col]) {
//                 // cout<< "isValid false, row: " << cur_row << ", col: " << cur_col << ", val: " << board[cur_row][cur_col] << ", check row: " << cur_row << ", check col: " << i << ", check val: " << board[cur_row][i] << "\n";
//                 return false;
//             }
//         }
//         //col check
//         for (int i = 0; i < 9; i++) {
//             if (i == cur_row) continue;
//             if (board[i][cur_col] == board[cur_row][cur_col]) {
//                 // cout<< "isValid false, row: " << cur_row << ", col: " << cur_col << ", val: " << board[cur_row][cur_col] << ", check row: " << i << ", check col: " << cur_col << ", check val: " << board[i][cur_col] << "\n";
//                 return false;
//             }
//         }
//         //3-3 check
//         int grid_row = cur_row / 3;
//         int grid_col = cur_col / 3;
//         for (int i = grid_row * 3; i < (grid_row + 1) * 3; i++) {
//             for (int j = grid_col * 3; j < (grid_col + 1) * 3; j++) {
//                 // cout<< "grid search, grid_row: " << grid_row << ", grid_col: " << grid_col << ", cur_row:" << cur_row << ", cur_col: " << cur_col  << "\n";
//                 if (i == cur_row && j == cur_col) continue;
//                 if (board[i][j] == board[cur_row][cur_col]) {
//                     // cout<< "isValid false, row: " << cur_row << ", col: " << cur_col << ", val: " << board[cur_row][cur_col] << ", check row: " << i << ", check col: " << j << ", check val: " << board[i][j] << "\n";
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

// template<int N, int M>
// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         if (board.size() != 9 || board[0].size() != 9) return;
//         int col[9];
//         int row[9];
//         int block[3][3];
//         memset(col, 0, sizeof(col));
//         memset(row, 0, sizeof(row));
//         memset(block, 0, sizeof(block));
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] == '.') continue;
//                 fillDigit(i, j , board[i][j] - '0' - 1, col, row, block);
//             }
//         }
//         int i = 1;
//         backTrack(board, 0, col, row, block);
//     }
//     void fillDigit(int i, int j, int digit, int (&col)[9], int (&row)[9], int (&block)[3][3]) {
//         row[i] ^= 1 << digit;
//         col[j] ^= 1 << digit;
//         block[i / 3][j / 3] ^= 1 << digit;
//     }
//     bool backTrack(vector<vector<char>>& board, int cur, int (&col)[9], int (&row)[9], int (&block)[3][3]) {
//         if (cur == 81) return true;
//         int cur_row = cur / 9;
//         int cur_col = cur % 9;
//         // if (cur_col == 0 && cur_row >= 1) {
//         //     cout << "last row, " << cur_row -1 << ", cur: " << cur << ", result: ";
//         //     for (int i = 0; i < 9; i++) {
//         //         cout << board[cur_row-1][i] << ", ";
//         //     }
//         //     cout <<endl;
//         // }
//         if (board[cur_row][cur_col] == '.') {
//             int avaliable_digit = ((1 << 9) - 1) & (~(row[cur_row] | col[cur_col] | block[cur_row / 3][cur_col / 3]));
//             while (avaliable_digit != 0) {
//                 int digitMask = avaliable_digit & (-avaliable_digit);
//                 avaliable_digit = avaliable_digit & (avaliable_digit - 1);
//                 int digit = __builtin_ctz(digitMask);
//                 // cout<< "cur_row:" << cur_row << ", cur_col: " << cur_col << ", digit: " << digit << ", val: " << (char)(digit + '0' + 1) << ", avaliable_digit: " << avaliable_digit << "\n";
//                 fillDigit(cur_row, cur_col, digit, col, row, block);
//                 board[cur_row][cur_col] = digit + '0' + 1;
//                 if (backTrack(board, cur + 1, col, row, block)) return true;
//                 fillDigit(cur_row, cur_col, digit, col, row, block);
//                 board[cur_row][cur_col] = '.';
//             }
//         } else {
//             if (backTrack(board, cur + 1, col, row, block)) return true;
//         }
//         return false;
//     }
// };


// class Solution {
// private:
//     int line[9];
//     int column[9];
//     int block[3][3];
//     bool valid;
//     vector<pair<int, int>> spaces;

// public:
//     void flip(int i, int j, int digit) {
//         line[i] ^= (1 << digit);
//         column[j] ^= (1 << digit);
//         block[i / 3][j / 3] ^= (1 << digit);
//     }

//     void dfs(vector<vector<char>>& board, int pos) {
//         if (pos == spaces.size()) {
//             valid = true;
//             return;
//         }

//         auto [i, j] = spaces[pos];
//         int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
//         for (; mask && !valid; mask &= (mask - 1)) {
//             int digitMask = mask & (-mask);
//             int digit = __builtin_ctz(digitMask);
//             flip(i, j, digit);
//             board[i][j] = digit + '0' + 1;
//             dfs(board, pos + 1);
//             flip(i, j, digit);
//         }
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         memset(line, 0, sizeof(line));
//         memset(column, 0, sizeof(column));
//         memset(block, 0, sizeof(block));
//         valid = false;

//         for (int i = 0; i < 9; ++i) {
//             for (int j = 0; j < 9; ++j) {
//                 if (board[i][j] == '.') {
//                     spaces.emplace_back(i, j);
//                 }
//                 else {
//                     int digit = board[i][j] - '0' - 1;
//                     flip(i, j, digit);
//                 }
//             }
//         }

//         dfs(board, 0);
//     }
// };


class Solution {
private:
    int line[9];
    int column[9];
    int block[3][3];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    void flip(int i, int j, int digit) {
        line[i] ^= (1 << digit);
        column[j] ^= (1 << digit);
        block[i / 3][j / 3] ^= (1 << digit);
    }

    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
        for (; mask && !valid; mask &= (mask - 1)) {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(digitMask);
            flip(i, j, digit);
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            flip(i, j, digit);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, 0, sizeof(line));
        memset(column, 0, sizeof(column));
        memset(block, 0, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '0' - 1;
                    flip(i, j, digit);
                }
            }
        }

        while (true) {
            bool if_set = false;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') continue;
                    int avaliable_digit = ((1 << 9) -1) & (~(line[i] | column[j] | block[i / 3][j / 3]));
                    if (!(avaliable_digit & (avaliable_digit - 1))) {
                        int digitMask = avaliable_digit & (-avaliable_digit);
                        int digit = __builtin_ctz(digitMask);
                        flip(i, j, digit);
                        board[i][j] = '0' + digit + 1;
                        if_set = true;
                    }
                }
            }
            if (!if_set) {
                break;
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                }
            }
        }
        dfs(board, 0);
    }
};
