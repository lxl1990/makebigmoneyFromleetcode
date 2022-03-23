class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
        while (start < n -1) {
            if (nums[start] != nums[start+1]) break;
            start++;
        }
        backTrack(ret, nums, start + 1, n, path);
    }
};
