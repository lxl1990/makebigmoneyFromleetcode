/*
    1、两向量长度分别为n1、n2
    当n1 + n2为偶数时，中位数为 (n1+n2)/2  (n1+n2)/2 + 1 的平均值
    当n1 + n2为奇数时，中位数为 (n1+n2)/2 + 1
    2、如果查找两排序数组的第k个数
        当 k = 1 时， return min(nums1[0], nums2[0])
        当 k > 1 时
            if (nums1[start1 + k/2] >= nums1[start2 + k/2])
                star2 = start2 + k/2;
            else
                star1 = start1 + k/2;
            k -= k/2;
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 + n2 == 0) return 0;
        if (((n1 + n2) & 1) == 0) {
            return (findKSortedArrays(nums1, nums2, 0, n1 - 1, 0, n2 - 1, (n1 + n2) >> 1) + findKSortedArrays(nums1, nums2, 0, n1 - 1, 0, n2 - 1, ((n1 + n2) >> 1) + 1)) / 2.0;
        } else {
            return findKSortedArrays(nums1, nums2, 0, n1 - 1, 0, n2 - 1, ((n1 + n2) >> 1) + 1);
        }
        return 0;
    }

    int findKSortedArrays(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2, int k) {
        if (start1 > end1) {
            return nums2[start2 + k - 1];
        }
        if (start2 > end2) {
            return nums1[start1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        } else {
            int newstart1 = min(start1 + k / 2 - 1, end1);
            int newstart2 = min(start2 + k / 2 - 1, end2);

            if (nums1[newstart1] >= nums2[newstart2]) {
                k -= newstart2 - start2 + 1;
                start2 = newstart2 + 1;
            } else {
                k -= newstart1 - start1 + 1;
                start1 = newstart1 + 1;
            }
            return findKSortedArrays(nums1, nums2, start1, end1, start2, end2, k);
        }
    }
};
