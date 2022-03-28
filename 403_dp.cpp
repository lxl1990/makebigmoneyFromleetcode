// class Solution {
// public:
//     bool canCross(vector<int>& stones) {
//         int len = stones.size();
//         if (len == 0) return true;
//         for (int i = 1; i < len; ++i) {
//             if (stones[i] - stones[i - 1] > i) {
//                 return false;
//             }
//         }
//         auto pairCmp = [](const auto& p1, const auto& p2) {
//             auto& [index1, step1] = p1;
//             auto& [index2, step2] = p2;
//             return index1 + step1 < index2 + step2;
//         };
//         priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(pairCmp)> queue(pairCmp);
//         queue.emplace(0, 0);
//         int ans = 0;
//         while (!queue.empty()) {
//             auto [index, step] = queue.top(); queue.pop();
//             if (index == len - 1) return true;
//             for (int curStep = step - 1; curStep <= step + 1; curStep++) {
//                 if (curStep > 0) {
//                     int new_index = lower_bound(stones.begin(), stones.end(), curStep + stones[index]) - stones.begin();
//                     if (new_index != stones.size() && stones[new_index] == curStep + stones[index]) {
//                         queue.emplace(new_index, curStep);
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     vector<unordered_map<int, int>> rec;

//     bool dfs(vector<int>& stones, int i, int lastDis) {
//         if (i == stones.size() - 1) {
//             return true;
//         }
//         if (rec[i].count(lastDis)) {
//             return rec[i][lastDis];
//         }
//         for (int curDis = lastDis - 1; curDis <= lastDis + 1; curDis++) {
//             if (curDis > 0) {
//                 int j = lower_bound(stones.begin(), stones.end(), curDis + stones[i]) - stones.begin();
//                 // cout <<lower_bound(stones.begin(), stones.end(), curDis + stones[i]) - stones.begin() << endl;
//                 if (j != stones.size() && stones[j] == curDis + stones[i] && dfs(stones, j, curDis)) {
//                     return rec[i][lastDis] = true;
//                 }
//             }
//         }
//         return rec[i][lastDis] = false;
//     }

//     bool canCross(vector<int>& stones) {
//         int n = stones.size();
//         rec.resize(n);
//         return dfs(stones, 0, 0);
//     }
// };

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j + 1) {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};
