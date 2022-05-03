// class Solution {
// public:
//     int minSteps(int n) {
//         vector<int> dp(n + 1, 0);
//         for (int k = 2; k <= n; k++) {
//             for (int i = 2; i*i <= k; i++) {
//                 if (k % i == 0) {
//                     dp[k] = i + dp[k / i];
//                     break;
//                 }
//             }
//             if (dp[k] == 0) dp[k] = k;
//         }
//         return dp[n];
//     }
// };


class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        if (n != 1) ans += n;
        return ans;
    }
};
