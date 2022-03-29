// /*
//     dp[i] = if dp[i-1]>0 ? dp[i-1] + nums[i] : nums[i]; 
// */
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int ans = 1 << 31;
//         int dp = -1;
//         for (int num: nums) {
//             if (dp < 0) {
//                 dp = num;
//             } else {
//                 dp = num + dp;
//             }
//             ans = max(ans, dp);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
