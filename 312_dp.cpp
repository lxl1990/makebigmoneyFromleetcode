/*
    nums两端添加1 1
    dp[i][j]两端保留，戳掉中间的最大数量
    dp[i][j] = max (dp[k][j] + dp[i][k] + nums[i] * nums[k] * nums[j])
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int pre = 1;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            nums[i] = pre;
            pre = tmp;
        }
        nums.emplace_back(pre);
        nums.emplace_back(1);
        int n = nums.size();
        // cout << "n: " << n << endl;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int k = 2; k <= n - 1; k++) {
            for (int i = 0; i + k < n; i++) {
                int j = i + k;
                for (int kk = i + 1; kk < j; kk++) {
                    dp[i][j] = max(dp[i][j], dp[i][kk] + dp[kk][j] + nums[i] * nums[kk] * nums[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
