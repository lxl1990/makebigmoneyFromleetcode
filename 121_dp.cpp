/*
    O(N)存储后缀最大数组，遍历一遍求解
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if (n <= 1) return 0;
//         vector<int> postMax;
//         int curMax = prices[n - 1];
//         postMax.emplace_back(curMax);
//         for (int i = n - 2; i >= 0; i--) {
//             if (prices[i] > curMax) curMax = prices[i];
//             postMax.emplace_back(curMax);
//         }
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (postMax[n - i - 1] - prices[i] > ans) ans = postMax[n - i - 1] - prices[i];
//         }
//         return ans;
//     }
// };


/*
    前缀最小数组，不需要额外存储
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int preMin = 1e5;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - preMin > ans) {
                ans = prices[i] - preMin;
            } else if (prices[i] < preMin) {
                preMin = prices[i];
            }
        }
        return ans;
    }
};
