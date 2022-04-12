/*
    dp[i][k]表示0-i安排k个邮筒
    dp[i][k] = dp[j][k-1] + middle(j+1, i)
    middle(i, j) 表示 i到j 使用一个邮箱
    middle(i, j) = middle(i + 1, j - 1) + houses[j] - houses[i]
*/
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        if (n <= 1) return 0;
        sort(houses.begin(), houses.end());
        vector<vector<int>> middle(n, vector<int>(n, 0));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                middle[i][j] = middle[i + 1][j - 1] + houses[j] - houses[i];
            }
        }
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = middle[0][i];
        }
        for (int m = 1; m < k; m++) {
            for (int i = n - 1; i > 0; i--) {
                int tmp = (int) (long (1 << 31) - 1);
                for (int j = i - 1; j >= 0; j--) {
                    tmp = min(tmp, dp[j] + middle[j + 1][i]);
                }
                dp[i] = tmp;
            }
        }
        return dp[n - 1];
    }
};
