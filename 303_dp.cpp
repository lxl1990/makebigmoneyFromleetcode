class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        preSum.emplace_back(0);
        for (int i = 1; i <= n; i++) {
            preSum.emplace_back(preSum[i - 1] + nums[i - 1]);
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
