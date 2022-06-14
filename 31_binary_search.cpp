/*
    get the biggest index i, s.t. nums[i] < nums[i+1]
    so that i + 1, ... , n-1 is sorted in descending order
    find the biggest index j s.t. nums[j] > nums[i], and swap nums[i] nums[j]
    then reverse [i+1, ... , n-1]
*/
class Solution {
private:
    int bianarySearch(int l, int r, function<bool(int)> f) {
        while (l + 1 != r) {
            int mid = l + ((r - l) >> 1);
            if (f(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int target = n - 2;
        while (nums[target] >= nums[target + 1]) {
            target--;
            if (target < 0) break;
        }
        // cout << "target: " << target << endl;
        if (target < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int biggerIndex = bianarySearch(target + 1, n, [&](int i) {return nums[i] > nums[target];});

        // cout << "biggerIndex: " << biggerIndex << endl;
        swap(nums[target], nums[biggerIndex]);
        reverse(nums.begin() + target + 1, nums.end());
    }
};
