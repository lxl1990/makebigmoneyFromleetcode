/*
    leftMax[i] = max(leftMax[i], leftMax[i-1])
    rightMax[i] = max(rightMax[i], rightMax[i+1])

    没必要使用O(n)空间复杂度

*/
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) return 0;
        int left = 0, right = len - 1;
        int leftMax = height[left], rightMax = height[right];
        int sum = 0;
        while (left < right) {
            if (leftMax < rightMax) {
                sum += leftMax - height[left];
                left++;
                leftMax = max(leftMax, height[left]);
            } else {
                sum += rightMax - height[right];
                right--;
                rightMax = max(rightMax, height[right]);
            }
        }
        return sum;
    }
};
