class Solution {
private:
    int binarySearch(int l, int r, function<bool(int)> f) {
        while (l + 1 != r) {
            int mid = l + ((r - l) >> 1);
            if (f(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            nums1[i] = nums1[i] - nums2[i];
        }
        sort(nums1.begin(), nums1.end());
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            int target = 1 - nums1[i];
            int right = binarySearch(i, n, [&](int k) {return nums1[k] >= target;});
            ret += n - right;
        }
        return ret;
    }

};
