/*
    similar to Question 873
    dp[i][j] is the length of subsequence end of nums[i] and nums[j];
    for example, the length of sequence {1, 2, 3} is 1, the length of sequence {1, 2} is 0;
    k is the index of 2*nums[i] - nums[j] if exists, then dp[i][j] = dp[i][k] + 1
    For the sequences whose values are all the same, we verify them separately;
*/

/*初版超时*/
// class Solution {
// private:
//     int findIndex(vector<int> vv, int target) {
//         int n = vv.size();
//         if (n == 0) return -1;
//         int left = -1, right = n;
//         while (left + 1 != right) {
//             int mid = left + (right - left) / 2;
//             if (vv[mid] < target) {
//                 left = mid;
//             } else {
//                 right = mid;
//             }
//         }
//         return left < 0 ? left : vv[left];
//     }
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 2) return n;
//         vector<vector<int>> numPosVec(501, vector<int>());
//         for (int i = 0; i < n; i++) {
//             numPosVec[nums[i]].emplace_back(i);
//         }
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         int ans = 2;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int leftVal = 2 * nums[i] - nums[j];
//                 if (leftVal >= 0 && leftVal <= 500) {
//                     int k = findIndex(numPosVec[leftVal], i);
//                     if (k != -1) {
//                         dp[i][j] = dp[k][i] + 1;
//                         ans = max(ans, dp[i][j] + 2);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

/*优化版，打败90%*/
// class Solution {
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 2) return n;
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         int ans = 2;
//         vector<int> numPosVec(501, -1);
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int leftVal = 2 * nums[i] - nums[j];
//                 if (leftVal >= 0 && leftVal <= 500) {
//                     int k = numPosVec[leftVal];
//                     if (k != -1) {
//                         dp[i][j] = dp[k][i] + 1;
//                         ans = max(ans, dp[i][j] + 2);
//                     }
//                 }
//             }
//             numPosVec[nums[i]] = i;
//         }
//         return ans;
//     }
// };

/*思路拓展篇 bit 6%
c++本身unordered_map只支持基础类型hash，懒得自己写hash算子，做了部分调整
参考SKX发布题解
重新定义状态，（i, step）以nums[i]结尾，差值为step
dp[i, step] = dp[j, step] + 1, j = index(nums[i] - step)
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        unordered_map<int, int> dp;
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int step = nums[j] - nums[i];
                int val = 2;
                if (dp.count(step * 1001 + i)) {
                    val = dp[step * 1001 + i] + 1;
                }
                if (dp.count(step * 1001 + j)) {
                    dp[step * 1001 + j] = val;
                } else {
                    dp.emplace(step * 1001 + j, val);
                }
                ans = max(dp[j + 1001 * step], ans);
            }
        }
        return ans;
    }
};
