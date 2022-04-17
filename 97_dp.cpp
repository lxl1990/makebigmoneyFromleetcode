/*
    dp[i][j]表示s1[:i] s2[:j]组成成功
    dp[i][j] = dp[i-1][j] && s1[i] == s3[i+j+1] || dp[i][j-1] && s2[j] == s3[i+j+1]
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        if (s3.size() != len1 + len2) return false;
        vector<int> dp(len2 + 1, false);
        dp[0] = true;
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i > 0) dp[j] &= (s1[i - 1] == s3[i + j - 1]);
                if (j > 0) dp[j] |= (dp[j - 1] && s2[j - 1] == s3[i + j -1]);
            }
        }
        return dp[len2];
    }
};


