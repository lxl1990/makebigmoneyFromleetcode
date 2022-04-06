/*
当前房子刷成什么颜色仅与之前房子颜色有关
dp[i][j]代表在第i个房子刷成color j时，0-i总花费
dp[i][j] = min (costs[i][j] + dp[i-1][j']).  where j' != j
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        vector<int> dp(3, 0);
        dp = costs[0];
        for (int i = 1; i < costs.size(); i++) {
            vector<int>dp2(3, 2000);
            for (int j = 0; j < 3; j++) {
                for (int j1 = 0; j1 < 3; j1++) {
                    if (j1 == j) continue;
                    dp2[j] = min(dp2[j], dp[j1] + costs[i][j]);
                }
                // cout << "i: " << i << ", j: " << j << ", val: " << dp2[j] << ", cost: " << costs[i][j] << endl;
            }
            dp.assign(dp2.begin(), dp2.end());
        }
        return *min_element(dp.begin(), dp.end());
    }
};


