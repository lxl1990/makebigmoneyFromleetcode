class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int ret = 0, preSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            if (map.count(preSum - k)) ret += map[preSum - k];
            map[preSum]++;
        }
        return ret;
    }
};
