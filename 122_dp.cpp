/*
    dp[i][0]、dp[i][1]分别表示在第i天持仓、空仓状态下最大值
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int takeProfit = (1 << 31);
//         int soldProfit = 0;
//         for (int i = 0; i < prices.size(); i++) {
//             int tmpTake = max(takeProfit, soldProfit - prices[i]);
//             int tmpSold = max(soldProfit, takeProfit + prices[i]);
//             takeProfit = tmpTake;
//             soldProfit = tmpSold; 
//         }
//         return max(takeProfit, soldProfit);
//     }
// };


/*
    贪心，获取每个区间的差值
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};
