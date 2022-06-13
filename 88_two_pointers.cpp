class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end1 = m - 1, end2 = n - 1;
        for (int i = 0; i < m + n; i++) {
            if (end2 < 0) break;
            if (end1 < 0 || nums2[end2] > nums1[end1]) {
                nums1[m + n - 1 - i] = nums2[end2];
                end2--;
            } else {
                nums1[m + n - 1 - i] = nums1[end1];
                end1--;
            }
        }
    }
};
