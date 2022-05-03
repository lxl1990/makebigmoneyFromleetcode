class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        for (int i = 1; i < n; i++) {
            int cur = min(dp[index2] * 2, min(dp[index3] * 3, dp[index5] * 5));
            dp[i] = cur;
            if (dp[index2] * 2 == cur) index2++;
            if (dp[index3] * 3 == cur) index3++;
            if (dp[index5] * 5 == cur) index5++;
        }
        return dp[n - 1];
    }
};
