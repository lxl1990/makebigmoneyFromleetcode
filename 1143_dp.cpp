/*
    dp[i][j] = max(dp[i-1][j-1] + (s1[i] == s[j]), dp[i-1][j], dp[i][j-1])
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        if (len1 == 0 || len2 == 0) return 0;
        vector<int> dp(len2 + 1, 0);
        for (int i = 0; i < len1; i++) {
            int preDiagonal = 0;
            for (int j = 0; j < len2; j++) {
                int tmp = dp[j + 1];
                if (text1[i] == text2[j]) {
                    dp[j + 1] = preDiagonal + 1;
                } else {
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                }
                preDiagonal = tmp;
            }
        }
        return dp[len2];
    }
};
