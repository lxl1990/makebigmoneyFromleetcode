class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0;
        int preSum = 0;
        unordered_map<int, int> map;
        map.insert({0, -1});
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            if (map.count(preSum - k)) {
                ans = max(ans, i - map[preSum - k]);
            }
            if (!map.count(preSum)) {
                map.insert({preSum, i});
            }
        }
        return ans;
    }
};
