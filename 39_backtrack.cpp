/*
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        int n = candidates.size();
        if (n == 0) return ret;
        vector<int> path;
        backtrack(ret, candidates, 0, target, n, path);
        return ret;
    }
    void backtrack(vector<vector<int>>& ret, const vector<int>& candidates, int start, int sum, int len, vector<int>& path) {
        if (sum == 0) {
            ret.push_back(path);
            return;
        }
        if (start == len || candidates[start] > sum) return;
        path.push_back(candidates[start]);
        sum -= candidates[start];
        backtrack(ret, candidates, start, sum, len, path);
        path.pop_back();
        sum += candidates[start];
        backtrack(ret, candidates, start + 1, sum, len, path);
    }
};
