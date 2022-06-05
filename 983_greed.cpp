class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int intMax = (int) ((long) (1 << 31) - 1);
        int dur[3] = {1, 7, 30};
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = intMax;
            int j = i;
            for (int k = 0; k < 3; k++) {
                while (j < n && days[j] < days[i] + dur[k]) {
                    j++;
                }
                dp[i] = min(dp[i], dp[j] + costs[k]);
            }
        }
        return dp[0];
    }
};
