/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
*/

//class Solution {
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        vector<vector<int>> ret;
//        vector<int> num_count(21, 0);
//        for (int num : nums) {
//            if (num > 10 || num < -10) return ret;
//            num_count[num + 10]++;
//        }
//        vector<int> path;
//        backtrack(ret, num_count, nums.size(), path, 0);
//        return ret;
//    }
//    void backtrack(vector<vector<int>>& ret, vector<int>& num_count, int n, vector<int>& path, int cur) {
//        if (cur == n) {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < 21; i++) {
//            if (num_count[i] == 0) continue;
//            num_count[i]--;
//            path.push_back(i - 10);
//            backtrack(ret, num_count, n, path, cur + 1);
//            num_count[i]++;
//            path.pop_back();
//        }
//    }
//};

class Solution {
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};
