class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                dp[i] = min(dp[i], 1 + dp[i - k * k]);
            }
            // cout << "i: " << i << ", val: " << dp[i] << endl;
        }
        return dp[n];
    }
};
