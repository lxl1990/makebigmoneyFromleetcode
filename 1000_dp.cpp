/*
    k + a * (k - 1) = n -> (a + 1) * (k - 1) = n - 1
    dp[i][j] = min(dp[i][i + a * (k - 1)] + dp[i+ a * (k - 1) + 1][j]);
    if (j-i) % (k-1) = 0: dp[i][j] = sum(stones[i:j])
*/
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + stones[i];
            // cout << "i: " << i << ", sum:" << sum[i+1] << endl;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = (int) (long (1 << 31) - 1);
                for (int a = 0; i + a * (k - 1) < j; a++) {
                    dp[i][j] = min(dp[i][j], dp[i][i + a * (k - 1)] + dp[i + a * (k - 1) + 1][j]);
                    // cout << "i: " << i << ", i + a * k: " << i + a * k << ", j: " << j << ", val: " << dp[i][i + a * (k - 1)] + dp[i + a * (k - 1) + 1][j] << endl;
                }
                // cout << "val: " << dp[i][j] << endl;
                if ((j-i) % (k-1) == 0) dp[i][j] += sum[j + 1] - sum[i];
                // cout << "i: " << i << ", j: " << j << ", val: " << dp[i][j] << endl;
            }
        }
        return dp[0][n - 1];
    }
};
