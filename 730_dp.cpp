typedef long long ll;
const long mod = 1e9 + 7; 
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    int l = i + 1, r = j - 1;
                    while (l <= r && s[l] != s[i]) l++;
                    while (l <= r && s[r] != s[j]) r--;
                    if (l == r) {
                        dp[i][j] -= 1;
                    }
                    else if (l < r) {
                        dp[i][j] -= 2 + dp[l+1][r-1];
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                dp[i][j] = dp[i][j] >= 0 ? dp[i][j] % mod : dp[i][j] % mod + mod;
            }
        }
        return dp[0][n - 1];
    }
};
