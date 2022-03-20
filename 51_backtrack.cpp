// class Solution {
//     public:
//         vector<vector<string>> solveNQueens(int n) {
//             vector<vector<int>> ret;
//             vector<int> path;
//             path.reserve(n);
//             findAllPath(ret, path, n);
//             vector<vector<string>> result(ret.size());
//             format_process(result, ret);
//             return result;
//         }
//         bool findAllPath(vector<vector<int>>& ret, vector<int>& path, int target) {
//             int cur_size = path.size();
//             for (int j = 0; j < cur_size - 1; j++) {
//                 if (path[j] == path[cur_size - 1]) return false;
//                 if (j - path[j] == cur_size - 1 - path[cur_size - 1]) return false;
//                 if (j + path[j] == cur_size - 1 + path[cur_size - 1]) return false;
//             }
//             if (cur_size == target) {
//                 return true;
//             }
//             for (int i = 0; i < target; i++) {
//                 path.push_back(i);
//                 if (findAllPath(ret, path, target)) {
//                     ret.push_back(vector<int>(path));
//                 }
//                 path.pop_back();
//             }
//             return false;
//         }
//         void format_process(vector<vector<string>>& result, vector<vector<int>>& ret) {
//             //[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//             // std::cout<<"sum: " << ret.size() << "\n";
//             for (int i = 0; i < ret.size(); i++) {
//                 vector<string> path(ret[i].size());
//                 for (int j = 0; j < ret[i].size(); j++) {
//                     string row(ret[i].size(), '.');
//                     row[ret[i][j]] = 'Q';
//                     path[j] = row;
//                     // std::cout<<"after: " << row << "\n";
//                 } 
//                 result[i] = path;
//             }
//         }
// };

// class Solution {
//     public:
//         vector<vector<string>> solveNQueens(int n) {
//             vector<int> path;
//             path.reserve(n);
//             unordered_set<int> columns;
//             unordered_set<int> diagonals1;
//             unordered_set<int> diagonals2;
//             vector<vector<string>> result;
//             backTrack(result, path, n, columns, diagonals1, diagonals2);
//             return result;
//         }
//         void backTrack(vector<vector<string>>& result, vector<int>& path, int target, unordered_set<int>& columns, unordered_set<int> diagonals1, unordered_set<int>& diagonals2) {
//             int row = path.size();
//             if (row == target) {
//                 result.push_back(generate_result(path));
//             } else {
//                 for (int i = 0; i < target; i++) {
//                     if (columns.find(i) != columns.end()) {
//                         continue;
//                     }
//                     if (diagonals1.find(row + i) != diagonals1.end()) {
//                         continue;
//                     }
//                     if (diagonals2.find(row - i) != diagonals2.end()) {
//                         continue;
//                     }
//                     path.push_back(i);
//                     columns.emplace(i);
//                     diagonals1.emplace(row + i);
//                     diagonals2.emplace(row - i);
//                     backTrack(result, path, target, columns, diagonals1, diagonals2);
//                     path.pop_back();
//                     columns.erase(i);
//                     diagonals1.erase(row + i);
//                     diagonals2.erase(row - i);
//                 }
//             }
//         }
//         vector<string> generate_result(vector<int>& path) {
//             vector<string> ret;
//             for (int i = 0; i < path.size(); i++) {
//                 string row(path.size(), '.');
//                 row[path[i]] = 'Q';
//                 ret.push_back(row);
//             } 
//             return ret;
//         }
// };


class Solution {
    public:
        std::vector<std::vector<string> > solveNQueens(int n) {
            std::vector<int> path;
            path.reserve(n);
            std::vector<std::vector<string> > result;
            backTrack(result, path, n, 0, 0, 0);
            return result;
        }
        void backTrack(std::vector<std::vector<string> > & result, std::vector<int>& path, int target, int columns, int diagonals1, int diagonals2) {
            // std::cout<<"backtrack: ";
            // output_every_vector(path);
            int row = path.size();
            if (row == target) {
                result.push_back(generate_result(path));
            } else {
                int available_positions = ((1 << target) - 1) & (~(columns | diagonals1 | diagonals2));
                // output_every_bit(available_positions);
                while (available_positions != 0) {
                    int position = available_positions & (-available_positions);
                    available_positions = available_positions & (available_positions - 1);
                    int column = 0;
                    int position_cp = position;
                    while ((position_cp & 1) == 0) {
                        position_cp >>= 1;
                        column++;
                    }
                    path.push_back(column);
                    backTrack(result, path, target, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
                    path.pop_back();
                }
            }
        }
        void output_every_bit(int n) {
            int i = 1;
            std::cout<<"available_positions: " << n <<", ";
            while (n != 0) {
                if (n & 1) {
                    std::cout<< i << ", ";
                }
                n >>= 1;
            }
            std::cout<< "\n";
        }
        void output_every_vector(std::vector<int>& path) {
            for (int i = 0; i < path.size(); i++) {
                std::cout<< path[i] << ", ";
            }
            std::cout<<"\n";
        }
        std::vector<string> generate_result(std::vector<int>& path) {
            std::vector<string> ret;
            for (int i = 0; i < path.size(); i++) {
                string row(path.size(), '.');
                row[path[i]] = 'Q';
                // std::cout << row << ", ";
                ret.push_back(row);
            } 
            // std::cout<< "\n";
            return ret;
        }

};
