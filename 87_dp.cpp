/*
    dp[i][j][len]定义为s1从i出发，s2从j出发，长度为len，是否互为扰动
    for k in [1, len - 1 ]
        if (dp[i][j][k] && dp[i+k][j+k][len-k])
            ||
           (dp[i][j+len-k][k] && dp[i+k][j][len-k]):
            dp[i][j][len] = true
            
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n) return false;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j][1] = 1;
                }
            }
        }
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= n; j++) {
                    for (int kk = 1; kk < k; kk++) {
                        bool a = dp[i][j][kk] && dp[i + kk][j + kk][k - kk];
                        bool b = dp[i][j + k - kk][kk] && dp[i + kk][j][k - kk];
                        if (a || b) {
                            dp[i][j][k] = 1;
                        }
                    }
                }
            }
        }
        return dp[0][0][n] == 1;
    }
};
