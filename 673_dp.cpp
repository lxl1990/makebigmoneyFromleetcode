/*
dp[i] = max(1, dp[j] + 1)
*/
// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         vector<vector<int>> dp(n, vector<int>(2, 1));
//         int maxLen = 1;
//         int ret = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 if (nums[i] > nums[j]) {
//                     if (dp[j][0] + 1 == dp[i][0]) {
//                         dp[i][1] += dp[j][1];
//                     } else if (dp[j][0] + 1 > dp[i][0]) {
//                         dp[i][0] = dp[j][0] + 1;
//                         dp[i][1] = dp[j][1];
//                     }
//                 }
//             }
//             if (dp[i][0] == maxLen) {
//                 ret += dp[i][1];
//             } else if (dp[i][0] > maxLen) {
//                 maxLen = dp[i][0];
//                 ret = dp[i][1];
//             }

//         }
//         return ret;
//     }
// };


class Solution {
private:
    int binarySearch(int n, function<bool(int)> f) {
        int l = -1, r = n;
        while (l + 1 != r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> dp, cnt;
        for (int num : nums) {
            //二分查找， dp中第一个尾部元素 >= num 的位置
            int index = binarySearch(dp.size(), [&](int i) {return dp[i].back() >= num;});
            // cout << "num: " << num << ", index: " << index << endl;
            int count = 1;
            if (index > 0) {
                int k = binarySearch(dp[index - 1].size(), [&](int i) {return dp[index - 1][i] < num;});
                count = cnt[index - 1].back() - cnt[index - 1][k];
            }
            if (index == dp.size()) {
                dp.emplace_back(vector<int>{num});
                cnt.emplace_back(vector<int>{0, count});
            } else {
                dp[index].emplace_back(num);
                cnt[index].emplace_back(cnt[index].back() + count);
            }
        }
        return cnt.back().back();
    }
};
