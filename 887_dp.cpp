/*
    k个鸡蛋，n层楼，最坏情况下的最小操作次数为f(k, n)
    第一次选择在哪层抛下
    for i in (1, ..., n)
        f(k, n) = max(f(k -1, i - 1), f(k, n - i)) + 1
    初始值f(k, 0) = 0, f(0, n) = maxVal
    超时
*/
// class Solution {
// public:
//     int superEggDrop(int k, int n) {
//         vector<vector<int>> dp(k + 1, vector<int>(n + 1, n));
//         for (int i = 0; i <= n; i++) {
//             dp[0][i] = n + 1;
//         }
//         for (int i = 0; i <= k; i++) {
//             dp[i][0] = 0;
//         }
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= k; j++) {
//                 for (int cur = 1; cur <= i; cur++) {
//                     int curTimes = max(dp[j - 1][cur - 1], dp[j][i - cur]) + 1;
//                     // cout << "i: " << i << ", j: " << j << ", cur: " << cur << ", val: " << curTimes << endl;
//                     dp[j][i] = min(curTimes, dp[j][i]);
//                 }
//             }
//         }
//         return dp[k][n];
//     }
// };

/*
  max(dp[k-1][x-1], dp[k][n-x])关于x求最小值，不用遍历求解
  直接使用二分查找解决 前项 等于 后向 的点
  问题是一定存在x, s.t. dp[k - 1][x - 1] = dp[k][n - x]吗？先假设存在写一版代码，跑起来看看
  上述问题一定存在，因为dp[k][x] 与 dp[k][x-1]、dp[k-1][x]至多相差1。
*/

// class Solution {
// public:
//     int superEggDrop(int k, int n) {
//         vector<vector<int>> dp(k + 1, vector<int>(n + 1, n));
//         for (int i = 0; i <= n; i++) {
//             dp[1][i] = i;
//         }
//         for (int i = 0; i <= k; i++) {
//             dp[i][0] = 0;
//         }
//         for (int i = 1; i <= n; i++) {
//             for (int j = 2; j <= k; j++) {
//                 int l = 0, r = i;
//                 while (l + 1 != r) {
//                     int mid = l + (r - l) / 2;
//                     if (dp[j - 1][mid - 1] < dp[j][i - mid]) {
//                         l = mid;
//                     } else {
//                         r = mid;
//                     }
//                 }
//                 dp[j][i] = max(dp[j - 1][r - 1], dp[j][i - r]) + 1;
//                 cout << "i: " << i << ", j: " << j << ", r: " << r << ", val: " << dp[j][i] << endl;
//             }
//         }
//         return dp[k][n];
//     }
// };

/*
    dp[k - 1][x - 1] = dp[k][n - x]的点，随着n增大而增大
*/
// class Solution {
// public:
//     int superEggDrop(int k, int n) {
//         vector<int> dp(n + 1, 0);
//         for (int i = 0; i <= n; i++) {
//             dp[i] = i;
//         }
//         for (int j = 2; j <= k; j++) {
//             vector<int> dp2(n + 1, 0);
//             int x = 1;
//             for (int i = 1; i <= n; i++) {
//                 while (x < i && max(dp[x - 1], dp2[i - x]) >= max(dp[x], dp2[i - x - 1])) {
//                     x++;
//                 }
//                 dp2[i] = 1 + max(dp[x - 1], dp2[i - x]);
//             }
//             for (int i = 1; i <= n; i++) {
//                 dp[i] = dp2[i];
//             }
//         }
//         return dp[n];
//     }
// };


/*
    逆向思维考虑： 如果有k个鸡蛋，m次机会，最多可以测试n层楼
    f(k, m) = 1 + f(k - 1, m - 1) + f(k, m - 1)
    初始条件：f(1, m) = m; f(k, 1) = 1;
    m <= n
*/
class Solution {
public:
    int superEggDrop(int k, int n) {
        if (n == 1) {
            return 1;
        }
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= k; ++i) {
            f[1][i] = 1;
        }
        int ans = -1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = 1 + f[i - 1][j - 1] + f[i - 1][j];
            }
            if (f[i][k] >= n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
