/*
    bfs + degree
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (m * n == 0) return 0;
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<int> outDegrees(m * n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int row = i + directions[k][0];
                    int col = j + directions[k][1];
                    // cout << "i: " << i << ", j: " << j << ", val: " << i * n + j << endl;
                    // cout << "row: " << row << ", col: " << col << endl;
                    if (row >= 0 && row < m && col >= 0 && col < n && matrix[row][col] > matrix[i][j]){
                        // cout << "true" << endl;              
                        outDegrees[i * n + j]++;
                    }
                }
            }
        }
        queue<int> que;
        for (int i = 0; i < m * n; i++) {
            if (outDegrees[i] == 0) {
                que.push(i);
                // cout << "push: " << i << endl;
            }
        }
        int ret = 0;
        while (!que.empty()) {
            ret++;
            int len = que.size();
            for (int i = 0; i < len; i++) {
                int curIndex = que.front();
                que.pop();
                int row = curIndex / n;
                int col = curIndex - row * n;
                for (int k = 0; k < 4; k++) {
                    int newRow = row + directions[k][0];
                    int newCol = col + directions[k][1];
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] < matrix[row][col]) {
                        outDegrees[newRow * n + newCol]--;
                        if (outDegrees[newRow * n + newCol] == 0) que.push(newRow * n + newCol);
                    }
                }
            }
        }
        return ret;
    }
};
