/*
    dp[i][0]、dp[i][1]
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int takeProfile = 1 << 31, sellProfile = 0;
        for (int price: prices) {
            takeProfile = max(takeProfile, sellProfile - price);
            sellProfile = max(sellProfile, takeProfile + price - fee);
        }
        return sellProfile;
    }
};
