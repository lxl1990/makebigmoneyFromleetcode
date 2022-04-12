/*
    dp[i][k]表示数组0-i，分割为k个子数组的解
    dp[i][k] = min { max(dp[j][k-1], sum(j+1, i)) }, where j in [0, i-1];
    sum(i, j) 为数组index i到j 的子数组和，可由前缀和解决
*/
// class Solution {
// public:
//     int splitArray(vector<int>& nums, int m) {
//         int n = nums.size();
//         vector<int> preSum(n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             preSum[i + 1] = preSum[i] + nums[i];
//         }
//         vector<int> dp(n, 0);
//         for (int k = 1; k <= m; k++) {
//             for (int i = n - 1; i >= 0; i--) {
//                 if (k == 1) {
//                     dp[i] = preSum[i + 1];
//                 } else {
//                     for (int j = 0; j < i; j++) {
//                         int tmp = max(dp[j], preSum[i + 1] - preSum[j + 1]);
//                         dp[i] = min(dp[i], tmp);
//                     }
//                 }
//             }
//         }
//         return dp[n - 1];
//     }
// };

/*
    二分查找，题解最小值为数组max(nums)，最大为sum(nums)
*/
class Solution {
private:
    bool check(vector<int>& nums, int val, int groupNum) {
        int cnt = 1; int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > val) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= groupNum;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0; int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            right += nums[i];
            left = max(left, nums[i]);
        }
        left--; right++;
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (check(nums, mid, m)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
        
    }
};
