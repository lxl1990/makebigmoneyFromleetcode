/*
    Similar to 1143，dp[i][j] means the answer of s1[0:i] and s2[0:j]
    if s1[i] == s2[j]
        dp[i][j] = dp[i-1][j-1]
    else
        dp[i][j] = min(dp[i][j-1] + (int) s2[j], dp[i-1][j] + (int) s1[i])
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        vector<int> dp(len2 + 1, 0);
        for (int i = 0; i < len2; i++) {
            dp[i + 1] = dp[i] + s2[i];
        }
        for (int i = 0; i < len1; i++) {
            int preDiagonal = dp[0];
            dp[0] += s1[i];
            for (int j = 0; j < len2; j++) {
                int tmp = dp[j + 1];
                if (s1[i] == s2[j]) {
                    dp[j + 1] = preDiagonal;
                } else {
                    dp[j + 1] = min(dp[j + 1] + (int) s1[i], dp[j] + (int) s2[j]);
                }
                preDiagonal = tmp;
            }
        }
        return dp[len2];
    }
};
