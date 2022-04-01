class Solution {
private:
    int calculate(vector<int>& slices, int start, int n, int choose) {
        vector<vector<int>> dp(n + 1, vector<int>(choose + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= choose; j++) {
                dp[i][j] = max((i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[start + i - 1], dp[i - 1][j]);
            }
        }
        return dp[n][choose];
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        if (n == 0) return 0;
        return max(calculate(slices, 0, n - 1, n / 3), calculate(slices, 1, n - 1, n / 3));
    }
};



/*下面这种贪心的方法才叫一绝*/
// class Solution {
// public:
//     int maxSizeSlices(vector<int>& slices) {
//         int n = slices.size();
//         if (n == 0) return 0;
//         vector<int> valid(n, 1);
//         vector<int>LinkLeft(n, 0), LinkRight(n, 0);
//         priority_queue<pair<int, int>> que;
//         for (int i = 0; i < n; i++) {
//             LinkLeft[i] = (i - 1 + n) % n;
//             LinkRight[i] = (i + 1) % n;
//             que.emplace(slices[i], i);
//             // cout << "i : " << i << ", left: " << LinkLeft[i] << ", right: " << LinkRight[i] << endl;
//         }
//         // cout << "top: " << que.top().first << endl;
//         int choose = n / 3;
//         int ans = 0;
//         for (int i = 0; i < choose; i++) {
//             while (!valid[que.top().second]) {
//                 que.pop();
//             }
//             int k = que.top().second;
//             que.pop();
//             ans += slices[k];
//             // cout << "k :" << k << ", ans: " << ans << endl;
//             valid[LinkLeft[k]] = 0;
//             valid[LinkRight[k]] = 0;
//             slices[k] = slices[LinkLeft[k]] + slices[LinkRight[k]] - slices[k];
//             que.emplace(slices[k], k);
//             LinkLeft[LinkRight[LinkRight[k]]] = k;
//             LinkRight[LinkLeft[LinkLeft[k]]] = k;
//             LinkLeft[k] = LinkLeft[LinkLeft[k]];
//             LinkRight[k] = LinkRight[LinkRight[k]];
//         }
//         return ans;
//     }
// };

