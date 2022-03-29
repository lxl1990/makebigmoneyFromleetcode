class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxV = nums[0], minV = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp1 = nums[i] * maxV, tmp2 = nums[i] * minV;
            maxV = max(nums[i], max(tmp1, tmp2));
            minV = min(nums[i], min(tmp1, tmp2));
            // cout << "max: " << maxV << ", min: " <<minV << endl;
            ans = max(ans, maxV);
        }
        return ans;
    }
};
