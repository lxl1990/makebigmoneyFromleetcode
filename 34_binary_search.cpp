class Solution {
private:
    int binaraySearch(int l, int r, int type, function<bool(int)> f) {
        while (l + 1 != r) {
            int mid = l + ((r - l) >> 1);
            if (f(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        // cout << "l:" << l << ", r:" << r <<endl;
        return type == 0 ? l : r;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftIndex = binaraySearch(-1, n, 1, [&](int i){return nums[i] < target;});
        int rightIndex = binaraySearch(-1, n, 0, [&](int i){return nums[i] <= target;});

        vector<int> ret(2, -1);
        if (leftIndex != n && nums[leftIndex] == target) {
            ret[0] = leftIndex;
        }
        if (rightIndex != -1 && nums[rightIndex] == target) {
            ret[1] = rightIndex;
        }
        return ret;
    }
};
