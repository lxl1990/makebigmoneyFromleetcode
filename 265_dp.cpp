// class Solution {
// public:
//     int minCostII(vector<vector<int>>& costs) {
//         int n = costs.size();
//         if (n == 0) return 0;
//         int k = costs[0].size();
//         vector<int> dp(k, 0);
//         dp = costs[0];
//         for (int i = 1; i < n; i++) {
//             int tmp 
//             for (int j = 0; j < k; j++) {
//                 for (int j1 = 0; j1 < k; j1++) {
//                     if (j1 == j) continue;
//                     dp2[j] = min(dp2[j], dp[j1] + costs[i][j]);
//                 }
//             }
//             dp.assign(dp2.begin(), dp2.end());
//         }
//         return *min_element(dp.begin(), dp.end());
//     }
// };

/*
    仅用维护一个最小值和次最小值即可
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        vector<int> dp(k, 0);
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            int tmp1 = 2000, tmp2 = 2000;
            vector<int> dp2(k, 0);
            for (int j = 0; j < k; j++) {
                if (dp[j] == c1) {
                    dp2[j] = costs[i][j] + c2;
                } else {
                    dp2[j] = costs[i][j] + c1;
                }
                if (dp2[j] < tmp1) {
                    tmp2 = tmp1;
                    tmp1 = dp2[j];
                } else if (dp2[j] < tmp2) {
                    tmp2 = dp2[j];
                }
            }
            c1 = tmp1;
            c2 = tmp2;
            dp.assign(dp2.begin(), dp2.end());
        }
        return *min_element(dp.begin(), dp.end());
    }
};
