class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxLen = 0;
        for (int num: nums) {
            if (num > maxLen) {
                maxLen = num;
            }
        }
        vector<int> v(maxLen + 1, 0);
        for (int num: nums) {
            v[num] += num;
        }
        
        int pre = 0, ppre = 0;
        for (int i = 1; i <= maxLen; i++) {
            int tmp = pre;
            pre = max(ppre + v[i], pre);
            ppre = tmp;
        }
        return max(pre, ppre);
    }
};
