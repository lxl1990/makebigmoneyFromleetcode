/*
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
    dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tokenProfile = 1 << 31;
        int psellProfile = 0, sellProfile = 0;
        // cout << "tokenProfile: " << tokenProfile << endl; 
        for (int i = 0; i < prices.size(); i++) {
            tokenProfile = max(tokenProfile, psellProfile - prices[i]);
            psellProfile = sellProfile;
            sellProfile = max(sellProfile, tokenProfile + prices[i]);
            // cout << "i: " << i << ", tokenProfile: " << tokenProfile << ", psellProfile" << psellProfile << ", sellProfile: " << sellProfile << endl;
        }
        return sellProfile;
    }
};
