// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int left = 0;
//         int right = n - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (target == nums[mid]) {
//                 return mid;
//             }
            
//             if (nums[0] <= nums[mid]) {
//                 if (nums[mid] > target && target >= nums[0]) {
//                     right = mid - 1;
//                 } else {
//                     left = mid + 1;
//                 }
//             } else {
//                 if (nums[mid] < target && target <= nums[n - 1]) {
//                     left = mid + 1;
//                 } else {
//                     right = mid - 1;
//                 }
//             }
//         }
//         return -1; 
//     }
// };


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int l = 0, r = n;
        //找到拐点
        while (l + 1 != r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        // cout << "l: " << l << ", r: " << r << endl;
        if(target >= nums[0]) {
            r = l + 1;
            l = -1;
        }
        else{
            l = l;
            r = n;
        }
        while(l + 1 != r){
            int mid = l + ((r - l) >> 1);
            if(nums[mid] <= target){
                l = mid;
            } else {
                r = mid;
            }
        }
        return (nums[l] == target ? l : -1);
    }
};
