/*
    pb[i][k]表示0-i k个硬币正面朝上的概率
    pk[i][k] = pk[i - 1][k] * (1-p[i]) + pk[i-1][k-1]*p[i]
    将k维度抹掉
*/
// class Solution {
// public:
//     double probabilityOfHeads(vector<double>& prob, int target) {
//         int n = prob.size();
//         if (n == 0) return 0.0;
//         vector<double> dp(n + 1, 0.0);
//         dp[0] = 1.0;
//         for (int i = 1; i <= n; i++) {
//             dp[i] = dp[i - 1] * (1.0 - prob[i - 1]);
//         }
//         for (int m = 1; m <= target; m++) {
//             vector<double> dp2(n + 1, 0.0);
//             for (int i = 1; i <= n; i++) {
//                 dp2[i] = dp2[i - 1] * (1 - prob[i - 1]) + dp[i - 1] * prob[i - 1];
//             }
//             dp.assign(dp2.begin(), dp2.end());
//         }
//         return dp[n];
//     }
// };


/*
    pb[i][k]表示0-i k个硬币正面朝上的概率
    pk[i][k] = pk[i - 1][k] * (1-p[i]) + pk[i-1][k-1]*p[i]
    将i维度抹掉
*/
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> dp(target + 1, 0.0);
        dp[0] = 1.0;
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= 1; j--) {
                dp[j] = dp[j] * (1.0 - prob[i]) + dp[j - 1] * prob[i];
            }
            dp[0] *= (1 - prob[i]);
        }     
        return dp[target];
    }
};
