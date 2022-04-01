/*
    第一家偷， 剩下无环3, n-1;
    第一家不偷，剩下无环1，n
*/
class Solution {
private:
    int rob_nocircle(vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        if (start == end) return nums[start];
        int ppre = 0, pre = 0;
        for (int i = start; i <= end; i++) {
            int tmp = pre;
            pre = max(ppre + nums[i], pre);
            ppre = tmp;
        }
        // cout << "start: " << start << ", end: " << end << ", pre: " << pre << ", ppre: " << ppre << endl; 
        return max(pre, ppre);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(nums[0] + rob_nocircle(nums, 2, nums.size() - 2), rob_nocircle(nums, 1, nums.size() - 1));
    }
};
