/*
    dp[i][j] is the sum of the submatrix with largest possible sum, whose lower right corner is (i, j);
    cell[i][j] is the upper left corner of corresponding matrix
    dp[i][j] = max(dp[i-1][j] + sum matrix[i][k], k in [cell[i-1][j][1], j], dp[i][j-1] + sum matrix[k][j], k in [cell[i][j][0], i],  matrix[i][j])
    解题错误
    更新二维转一维: 固定上下边界，边界内求一维最大（Kadane算法、 前缀）
*/
// class Solution {
// public:
//     vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         if (m == 0) return vector<int>();
//         int n = matrix[0].size();
//         vector<int> ans(4, 0);
//         int maxLen = 1 << 31;
//         for (int i = 0; i < m; i++) {
//             vector<int> b(n, 0);
//             int upper = i;
//             for (int j = i; j < m; j ++) {
//                 int sum = 0;
//                 int left = 0;
//                 for (int k = 0; k < n; k++) {
//                     b[k] += matrix[j][k];
//                     if (sum >= 0) {
//                         sum += b[k];
//                     } else {
//                         sum = b[k];
//                         left = k;
//                     }
//                     if (sum > maxLen) {
//                         maxLen = sum;
//                         ans[0] = upper;
//                         ans[1] = left;
//                         ans[2] = j;
//                         ans[3] = k;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return vector<int>();
        int n = matrix[0].size();
        vector<vector<int>> preSum(m + 1, vector<int>(n+1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                preSum[i][j] = matrix[i - 1][j - 1] + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
            }
        }
        // cout << "preSum end" << endl;
        vector<int> ans(4, 0);
        int maxLen = 1 << 31;
        for (int upper = 0; upper < m; upper++) {
            for (int down = upper; down < m; down ++) {
                int Left = 0;
                int sum = 0;
                for (int right = 0; right < n; right++) {
                    sum = preSum[down + 1][right + 1] + preSum[upper][Left] - preSum[down + 1][Left] - preSum[upper][right + 1];
                    // cout << "upper: " << upper << ", Left: " << Left << ", down: " << down << ", right: " << right << ", sum: " << sum << endl;
                    if (sum > maxLen) {
                        ans[0] = upper;
                        ans[1] = Left;
                        ans[2] = down;
                        ans[3] = right;
                        maxLen = sum;
                    }
                    if (sum < 0) {
                        Left = right + 1;
                        sum = 0;
                    }
                }
            }
        }
        return ans;
    }
};
