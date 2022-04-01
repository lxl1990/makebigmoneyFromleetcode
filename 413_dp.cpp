/*
   连续序列，记录diff，，以该元素结尾的最长连续序列的长度，即为新增等差数列个数
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 0;
        int ans = 0;
        int diff = nums[1] - nums[0];
        int maxLen = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == diff) {
                maxLen++;
            } else {
                diff = nums[i] - nums[i - 1];
                maxLen = 0;
            }
            ans += maxLen;
        }
        return ans;
    }
};
