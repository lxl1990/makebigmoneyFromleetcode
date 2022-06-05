/*
    priority_queue
*/
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
//         for (int i = 0; i < k; i++) {
//             pq.push(nums[i]);
//         }
//         for (int i = k; i < nums.size(); i++) {
//             if (nums[i] > pq.top()) {
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
//         // std::cout << pq.size();
//         return pq.top();
//     }
// };

/*
    quick sort
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (true) {
            int index = partition(nums, l, r);
            if (index == k - 1) {
                return nums[index];
            } else if (index < k - 1) {
                l = index + 1;
            } else {
                r = index - 1;
            }
        }
    }
    int partition(vector<int>& nums, int start, int end) {
        int i = start + 1, j = end, t = nums[start];
        while (i <= j) {
            while (nums[i] > t && i <= j) i++;
            while (nums[j] < t) j--;
            if (i > j) break;
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        swap(nums[start], nums[j]);
        return j;
    }
};
