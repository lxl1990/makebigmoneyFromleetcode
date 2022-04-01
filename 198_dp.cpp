/*
dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
ppre代表不偷前次情况下，最大金额； pre代表偷前次情况下最大金额
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int ppre = 0, pre = 0;
        for (int num: nums) {
            int cur = num + ppre;
            ppre = max(pre, ppre);
            pre = cur;
        }
        return max(pre, ppre);
    }
};




