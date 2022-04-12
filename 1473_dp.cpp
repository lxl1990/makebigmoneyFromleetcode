/*
    dp[i][j][k]表示0-i房子在第i个房子涂色为j，前i有k个街区的情况下，涂色的最小花费
    dp[i][j][k] = min (dp[i-1][j][k], dp[i-1][j'][k-1]) + cost[i][j], 且涂色合理，不合理为无穷大（可取10^6）
*/

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n, vector<int>(target + 1, 1e7)));
        for (int j = 0; j < n; j++) {
            dp[0][j][0] = 0;
        }

        vector<vector<vector<int>>> best(m + 1, vector<vector<int>>(target + 1, {10000000, -1, 1000000}));
        best[0][0] = {0, 0, 0};
        
        for (int i = 1; i <= m; i++) {
            for (int k = 1; k <= target; k++) {
                if (k > i) continue;
                if (houses[i - 1] != 0) {
                    int j = houses[i - 1] - 1;
                    dp[i][j][k] = dp[i - 1][j][k];
                    dp[i][j][k] = min(dp[i][j][k], best[i - 1][k - 1][1] == j ? best[i - 1][k - 1][2] : best[i - 1][k - 1][0]);
                    //for (int j1 = 0; j1 < n; j1++) {
                    //    if (j1 == j) continue;
                    //    cout << "dp[i - 1][j1][k - 1]:" << dp[i - 1][j1][k - 1] << "dp[i][j][k]: " << dp[i][j][k] << endl;
                    //    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j1][k - 1]);
                    //}
                    // cout << "i: " << i << ", j:" << j << ", k: " << k << ", val: " << dp[i][j][k] << endl;
                } else {
                    for (int j = 0; j < n; j++) {
                        dp[i][j][k] = dp[i - 1][j][k];
                        dp[i][j][k] = min(dp[i][j][k], best[i - 1][k - 1][1] == j ? best[i - 1][k - 1][2] : best[i - 1][k - 1][0]);
                        //for (int j1 = 0; j1 < n; j1++) {
                        //    if (j1 == j) continue;
                        //    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j1][k - 1]);
                        //}
                        dp[i][j][k] += cost[i - 1][j];
                        // cout << "i: " << i << ", j:" << j << ", k: " << k << ", val: " << dp[i][j][k] << endl;
                    }
                }
                auto& update_best = best[i][k];
                for (int j = 0; j < n; j++) {
                    if (dp[i][j][k] < update_best[0]) {
                        update_best[2] = update_best[0];
                        update_best[1] = j;
                        update_best[0] = dp[i][j][k];
                    } else if (dp[i][j][k] < update_best[2]) {
                        update_best[2] = dp[i][j][k];
                    }
                }
            }
        }
        return best[m][target][0] >= 1e7 ? -1 : best[m][target][0];
    }
};
