// /*
// nums排序
// dp[i]为以nums[i]结尾的，最大整除子集的长度
// dp[i] = max(dp[j] + 1 and nums[i] % nums[j] == 0)
// */
// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return vector<int>();
//         sort(nums.begin(), nums.end());
//         vector<int> d(n, 0);
//         vector<int> p(n, 0);
//         d[0] = 1;
//         p[0] = 0;
//         int ans = 0;
//         int maxLen = 1;
//         for (int i = 1; i < n; i++) {
//             int from = i, len = 1;
//             for (int j = i - 1; j >= 0; j--) {
//                 if (nums[i] % nums[j] == 0 && d[j] >= len) {
//                     len = d[j] + 1;
//                     from = j;
//                 }
//                 if (len > maxLen) {
//                     ans = i;
//                     maxLen = len;
//                 }
//                 if (len >= j + 1) break;
//             }
//             d[i] = len;
//             p[i] = from;
//         }
//         vector<int> ret;
//         ret.emplace_back(nums[ans]);
//         while (ret.size() != maxLen) {
//             ans = p[ans];
//             ret.emplace_back(nums[ans]);
//         }
//         return ret;
//     }
// };

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        // 第 1 步：动态规划找出最大子集的个数、最大子集中的最大整数
        vector<int> dp(len, 1);
        int maxSize = 1;
        int maxVal = dp[0];
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                // 题目中说「没有重复元素」很重要
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }

        // 第 2 步：倒推获得最大子集
        vector<int> res;
        if (maxSize == 1) {
            res.push_back(nums[0]);
            return res;
        }

        for (int i = len - 1; i >= 0 && maxSize > 0; i--) {
            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                res.push_back(nums[i]);
                maxVal = nums[i];
                maxSize--;
            }
        }
        return res;
    }
};
