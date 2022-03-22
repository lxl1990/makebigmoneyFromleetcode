//class Solution {
//public:
//    bool makesquare(vector<int>& matchsticks) {
//        sort(matchsticks.begin(), matchsticks.end());
//        int sum = 0;
//        for (int num : matchsticks) {
//            sum += num;
//        }
//        int target = sum / 4;
//        if (target * 4 != sum) return false;
//        int n = matchsticks.size();
//        vector<int> group(4, 0);
//        return dfs(matchsticks, n - 1, group, sum / 4);
//    }
//    bool dfs(vector<int>& matchsticks, int index, vector<int>& group, int target) {
//        //cout<< "index: " << index << ", n: " << n << ", target: " << target << endl;
//        if (index < 0) return true;
//        for (int i = 0; i < 4; i++) {
//            group[i] += matchsticks[index];
//            if (group[i] <= target && dfs(matchsticks, index - 1, group, target)) return true;
//            group[i] -= matchsticks[index];
//        }
//        return false;
//    }
//};


//class Solution {
//private:
//    unordered_map<int, bool> cache_map;
//public:
//    bool makesquare(vector<int>& matchsticks) {
//        sort(matchsticks.begin(), matchsticks.end());
//        int sum = 0;
//        for (int num : matchsticks) {
//            sum += num;
//        }
//        int target = sum / 4;
//        if (target * 4 != sum) return false;
//        int n = matchsticks.size();
//        int mask = ((1 << n) - 1);
//        return backtrack(matchsticks, n, mask, target);
//    }
//    bool backtrack(vector<int>& matchsticks, int n, int mask, int target) {
//        if (cache_map.find(mask) != cache_map.end()) {
//            return cache_map[mask];
//        }
//        int total = 0;
//        for (int i = 0; i < n; i++) {
//            if ((mask & (1 << i)) == 0) {
//                total += matchsticks[i];
//            }
//        }
//        int couple = total / target;
//        int residual = target * (couple + 1) - total;
//        if (couple == 3 && residual == target) return true;
//        for (int i = 0; i < n; i++) {
//            if (matchsticks[i] <= residual && (mask & (1 << i)) > 0 && backtrack(matchsticks, n, mask ^ (1 << i), target)) {
//                cache_map[mask] = true;
//                return true;
//            }
//        }
//        cache_map[mask] = false;
//        return false;
//    }
//};

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end());
        int sum = 0;
        for (int num: matchsticks) {
            sum += num;
        }
        int target = sum / 4;
        if (target * 4 != sum) return false;
        int n = matchsticks.size();
        if (matchsticks[n-1] > target) return false;
        //cout << "n:" << n << endl;
        vector<int> dp((1 << n), target + 1);
        dp[0] = 0;
        //cout << "1 << n:" << (1 << n) << endl;
        for (int mask = 0; mask < (1 << n); mask++) {
            //cout<<"mask: " << mask << endl;
            for (int i = 0; i < n; i++) {
                //cout << "i: " << i << ", (mask & (1 << i): " << (mask & (1 << i)) << ", mask - (1 << i)" << (mask - (1 << i)) << endl;
                if ((mask & (1 << i)) == 0) continue;
                if ((dp[mask - (1 << i)] + matchsticks[i]) > target) continue;
                dp[mask] = (dp[mask - (1 << i)] + matchsticks[i]) % target;
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};
