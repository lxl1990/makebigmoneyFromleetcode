class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n == 0) return ret;
        vector<int> path;
        backTrack(ret, nums, 0, n, path);
        return ret;
    }
    void backTrack(vector<vector<int>>& ret, const vector<int>& nums, int start, int n, vector<int>& path) {
        if (start == n) {
            ret.emplace_back(path);
            return;
        }
        path.push_back(nums[start]);
        backTrack(ret, nums, start + 1, n, path);
        path.pop_back();
        backTrack(ret, nums, start + 1, n, path);
    }
};

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ret;
//         int n = nums.size();
//         for (int i = 0; i < (1 << n); i++) {
//             vector<int> path;
//             for (int j = 0; j < n; j++) {
//                 if ((i & (1 << j)) > 0) path.push_back(nums[j]);
//             }
//             ret.emplace_back(path);
//         }
//         return ret;
//     }
// };
