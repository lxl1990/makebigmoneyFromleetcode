/*
    dp[i][k] 表示将i至结尾分为k份，最大值，dp[i][k]为遍历i-n，将前半部分划为一组，后面划分k-1组；由于k只用到k-1，因此这个维度结果不用保存
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        vector<double> dp(n, 0.0);
        for (int i = 0; i < n; i++) {
            dp[i] = (preSum[n] - preSum[i]) / (n - i);
        }
        for (int group = 1; group < k; group++) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    dp[i] = max(dp[i], (preSum[j] - preSum[i]) / (j - i) + dp[j]);
                }
            }
        }
        return dp[0];
    }
};
