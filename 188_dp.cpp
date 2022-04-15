/*
    dp[i][j][k] 代表第i天处于第k次交易, j状态代表持仓、空仓两种
    dp[i][0][k] = max(dp[i-1][0][k], dp[i-1][1][k] + prices[i]);
    dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][0][k-1] - prices[i]);
*/
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         vector<int> takeProfile(k + 1, 1 << 31);
//         vector<int> soldProfile(k + 1, 0);
//         for (int i = 0; i < prices.size(); i++) {
//             for (int j = 1; j <= k; j++) {
//                 takeProfile[j] = max(takeProfile[j], soldProfile[j - 1] - prices[i]);
//                 soldProfile[j] = max(soldProfile[j], takeProfile[j] + prices[i]);
//             }
//         }
//         return soldProfile[k];
//     }
// };


/*
    wqs 二分
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        int left = 1, right = *max_element(prices.begin(), prices.end());
        int ans = -1;
        while (left <= right) {
            int c = (left + right) / 2;

            int buyCount = 0, sellCount = 0;
            int buy = -prices[0], sell = 0;

            for (int i = 1; i < n; ++i) {
                if (sell - prices[i] >= buy) {
                    buy = sell - prices[i];
                    buyCount = sellCount;
                }
                if (buy + prices[i] - c >= sell) {
                    sell = buy + prices[i] - c;
                    sellCount = buyCount + 1;
                }
            }

            if (sellCount >= k) {
                // 别忘了加上 kc
                ans = sell + k * c;
                left = c + 1;
            }
            else {
                right = c - 1;
            }
        }

        if (ans == -1) {
            ans = 0;
            for (int i = 1; i < n; ++i) {
                ans += max(prices[i] - prices[i - 1], 0);
            }
        }

        return ans;
    }
};
