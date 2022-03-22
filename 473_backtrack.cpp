class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end());
        int sum = 0;
        for (int num : matchsticks) {
            sum += num;
        }
        int target = sum / 4;
        if (target * 4 != sum) return false;
        int n = matchsticks.size();
        vector<int> group(4, 0);
        return dfs(matchsticks, n - 1, group, sum / 4);
    }
    bool dfs(vector<int>& matchsticks, int index, vector<int>& group, int target) {
        //cout<< "index: " << index << ", n: " << n << ", target: " << target << endl;
        if (index < 0) return true;
        for (int i = 0; i < 4; i++) {
            group[i] += matchsticks[index];
            if (group[i] <= target && dfs(matchsticks, index - 1, group, target)) return true;
            group[i] -= matchsticks[index];
        }
        return false;
    }
};
