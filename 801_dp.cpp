/*
    定义状态，两种数组常方式dp[i][j]. dp[i]，两边同时伸缩的方式没有益处，图增加计算；
    暂时可以考虑采用dp[i], 0-i最小次数；
    由dp[i-1]推理计算dp[i]，无法确定i-1处索引具体取值，因此还得增加一个纬度
    dp[i][0]、dp[i][1]分别代表i处不发生交换、发生交换的前提下最小交换次数
    而如果当前索引发生逆序即 nums1[i] <= nums1[i-1] 或者 nums2[i] <= nums1[i-1]，则需要替换i-1 或者i 处； 如果交换 i-1 处，需要知道dp[i-1][1], 假设0到i-1不交换即可满足条件，那这种情况需要具体列出；
    总结： 第一种情况满足条件交换， 不满足条件交换
*/
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if (n <= 1) return 0;
        int dp1 = 1, dp0 = 0;
        for (int i = 1; i < n; i++) {
            int cur1 = 0, cur0 = 0;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                //该种情况，已经满足条件，需要根据前者数据情况确定是否需要交换
                if (nums2[i] > nums1[i - 1] && nums1[i] > nums2[i - 1]) {
                    cur1 = min(dp0, dp1) + 1;
                    cur0 = min(dp0, dp1);
                } else {
                    cur1 = dp1 + 1;
                    cur0 = dp0;
                }  
            } else {
                cur0 = dp1;
                cur1 = dp0 + 1;
            }
            dp0 = cur0;
            dp1 = cur1;
            // cout << "i: " << i << ", val: " << dp[i][0] << ", " << dp[i][1] << endl;
        }
        return min(dp0, dp1);
    }
};
