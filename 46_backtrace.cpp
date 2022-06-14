class Solution {
private:
    void dfs(vector<vector<int>>& ret, vector<int>& nums, vector<int>& used, list<int>& path, int n) {
        if (path.size() == n) {
            ret.emplace_back(vector<int>(path.begin(), path.end()));
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                used[i] = 1;
                path.emplace_back(nums[i]);
                dfs(ret, nums, used, path, n);
                path.pop_back();
                used[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        if (n == 0) return ret;
        vector<int> used(n, 0);
        list<int> path;
        dfs(ret, nums, used, path, n);
        return ret;
    }
};
