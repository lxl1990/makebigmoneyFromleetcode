class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> ans;
        if (m == 0) return ans;
        int n = matrix[0].size();
        if (n == 0) return ans;
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int globalMax = matrix[0][0];
        ans = {0, 0, 0, 0};
        for (int bottom = 1; bottom <= m; bottom++) {
            for (int up = bottom; up <= m; up++) {
                int left = 1;
                for (int right = 1; right <= n; right++) {
                    int localMax = sum[up][right] - sum[bottom - 1][right] - sum[up][left - 1] + sum[bottom - 1][left - 1];
                    if (localMax > globalMax) {
                        globalMax = localMax;
                        ans = {bottom - 1, left - 1, up - 1, right - 1};
                    }
                    if (localMax < 0) {
                        left = right + 1;
                    }
                }
            }
        }
        return ans;
    }
};
