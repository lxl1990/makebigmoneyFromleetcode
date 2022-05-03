/*
    dp[k]代表按键k次，最多可以返回多少个A
    dp[k] = max(dp[k-1] + 1, max{i * dp[k-i-1], 对于i in [2, k - 2]})
*/
// class Solution {
// public:
//     int maxA(int n) {
//         vector<int> dp(n + 1, 0);
//         for (int k = 1; k <= n; k++) {
//             dp[k] = k;
//             for (int i = 2; i <= k - 2; i++) {
//                 dp[k] = max(dp[k], i * dp[k - i - 1]);
//             }
//         }
//         return dp[n];
//     }
// };


/*
不能一直连乘
比较连乘k次再cp *2，需要k+4步
与连乘2k次，需要2k+1步
最多不能连乘6步（5步）
*/
class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1, 0);
        for (int k = 1; k <= n; k++) {
            dp[k] = k;
            for (int i = 2; i <= k - 2 && i <= 5; i++) {
                dp[k] = max(dp[k], i * dp[k - i - 1]);
            }
        }
        return dp[n];
    }
};
