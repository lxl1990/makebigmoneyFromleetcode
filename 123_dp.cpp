/*
    dp[i][j][k] 代表第i天处于第k次交易, j状态代表持仓、空仓两种
    dp[i][0][k] = max(dp[i-1][0][k], dp[i-1][1][k] + prices[i]);
    dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][0][k-1] - prices[i]);
*/

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int d01 = 1 << 31, d11 = 1 << 31;
//         int d02 = 1 << 31, d12 = 1 << 31;
//         for (int i = 0; i < prices.size(); i++) {
//             int d01_cur = 1 << 31, d11_cur = 1 << 31;
//             int d02_cur = 1 << 31, d12_cur = 1 << 31;
//             d11_cur = max(d11, - prices[i]);
//             if (i > 0) d01_cur = max(d01, d11 + prices[i]);
//             if (i > 1) d12_cur =  max(d12, d01 - prices[i]);
//             if (i > 2) d02_cur = max(d02, d12 + prices[i]);
//             d01 = d01_cur, d11 = d11_cur;
//             d02 = d02_cur, d12 = d12_cur;
//         }
//         return max(0, max(d01, d02));
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = 1 << 31, sell2 = 1 << 31;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return max(sell1, sell2);
    }
};
