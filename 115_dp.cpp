// /*
//     dp[i][j] 表示 s[i:] 中包含几个t[j:]
//     if (s[i] == s[j])
//         dp[i][j] = dp[i+1][j+1] + dp[i+1][j]
//     else
//         dp[i][j] = dp[i+1][j]
// */
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        if (len1 < len2) return 0;
        vector<long long> dp(len2 + 1, 0);
        dp[len2] = 1;
        for (int i = len1; i >= 0; i--) {
            int pre = dp[len2];
            for (int j = len2 - 1; j >=0; j--) {
                int tmp = dp[j];
                if (i < len1) dp[j] += s[i] == t[j] ? pre : 0;
                pre = tmp;
            }
        }
        return (int)dp[0];
    }
};

