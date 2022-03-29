// /*
//     用数组存储递增子序结果，新输入一个元素，找到第一个不小于新元素的位置并替换
//     for item from 0 to i, the longest strictly increasing subsequence is vv,;
//     user nums[i + 1], repalce vv[j], where vv[j-1] < nums[i+1], and vv[j] >= nums[i+1]
// */
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> ret;
//         for (int i = 0; i < nums.size(); i++) {
//             int len = ret.size();
//             if (len == 0) {
//                 ret.emplace_back(nums[i]);
//                 continue;
//             }
//             // cout << "num: " << nums[i] << endl;
//             int left = -1, right = len;
//             // cout << "left: " << left << ", right: " << right << endl;
//             while (left + 1 != right) {
//                 int mid = left + (right - left) / 2;
//                 if (ret[mid] < nums[i]) {
//                     left = mid;
//                 } else {
//                     right = mid;
//                 }
//                 // cout << "left: " << left << ", right: " << right << endl;
//             }
//             if (right == len) {
//                 ret.emplace_back(nums[i]);
//             } else {
//                 ret[right] = nums[i];
//             }
//             // cout << "right: " << right << ", val: " << ret[right] << endl;
//         }
//         return ret.size();
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = (int)nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         vector<int> dp(n, 0);
//         for (int i = 0; i < n; ++i) {
//             dp[i] = 1;
//             for (int j = 0; j < i; ++j) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }
//         return *max_element(dp.begin(), dp.end());
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
