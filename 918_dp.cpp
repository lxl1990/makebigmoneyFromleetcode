/*超时*/
// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         int ans = 1 << 31;
//         for (int i = 0; i < 2 * n; i++) {
//             int tmp = -1;
//             for (int j = max(i - n + 1, 0); j <= i; j++) {
//                 if (tmp < 0) {
//                     tmp = nums[j % n];
//                 } else {
//                     tmp += nums[j % n];
//                 }
//             }
//             ans = max(ans, tmp);
//         }
//         return ans;
//     }
// };

/*两段式*/
// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         int ans = nums[0], cur = nums[0];
//         for (int i = 1; i < n; i++) {
//             cur = nums[i] + max(0, cur);
//             ans = max(ans, cur);
//         }
//         //求右区间最大的值
//         vector<int> rightSum(n, 0);
//         rightSum[n - 1] = nums[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             rightSum[i] = nums[i] + rightSum[i + 1];
//         }
//         vector<int> maxRight(n, 0);
//         maxRight[n - 1] = rightSum[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             maxRight[i] = max(rightSum[i], maxRight[i + 1]);
//         }
//         int leftSum = 0;
//         for (int i = 0; i < n - 2; i++) {
//             leftSum += nums[i];
//             ans = max(ans, leftSum + maxRight[i + 2]);
//         }
//         return ans;
//     }
// };


/* 前向累积和 单调队列*/
// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         vector<int> preSum(2 * n + 1, 0);
//         for (int i = 0; i < 2 * n; i++) {
//             preSum[i + 1] = preSum[i] + nums[i % n];
//         }
//         int ans = nums[0];
//         list<int> ll;
//         ll.emplace_back(0);
//         for (int i = 1; i <= 2 * n; i++) {
//             if (ll.front() < i - n) {
//                 ll.pop_front();
//             }
//             ans = max(ans, preSum[i] - preSum[ll.front()]);
//             while (!ll.empty() && preSum[i] <= preSum[ll.back()]) {
//                 ll.pop_back();
//             }
//             ll.emplace_back(i);
//         }
//         return ans;
//     }
// };


/*
    Kadane算法
*/
class Solution {

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int ans1 = kadane(nums, 0, n - 1, 1);
        // cout << "ans1:" << ans1 << endl;
        int ans2 = n >= 2 ? kadane(nums, 0, n - 2, -1) : 0;
        // cout << "ans2:" << ans2 << endl;
        int ans3 = n >= 2 ? kadane(nums, 1, n - 1, -1) : 0;
        // cout << "ans3:" << ans3 << endl;
        return max(ans1, sum + max(ans2, ans3));
    }
    int kadane(vector<int>& nums, int start, int end, int sign) {
        int ans = 1 << 31;
        int cur = 1 << 31;
        for (int i = start; i <= end; i++) {
            cur = max(0, cur) + sign * nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};


