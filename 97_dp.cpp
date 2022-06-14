/*dfs + recursion*/
// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         if (s1.size() + s2.size() != s3.size()) return false;
//         return isInterleave(s1, s2, s3, 0, 0);
//     }
//     bool isInterleave(string& s1, string& s2, string& s3, int start1, int start2) {
//         if (start1 + start2 == s3.size()) return true;
//         if (start1 < s1.size() && s3[start1 + start2] == s1[start1]) {
//             if (isInterleave(s1, s2, s3, start1 + 1, start2)) return true;
//         }
//         if (start2 < s2.size() && s3[start1 + start2] == s2[start2]) {
//             if (isInterleave(s1, s2, s3, start1, start2 +1)) return true;
//         }
//         return false;
//     }
// };

/*
dp[i][j] indicates whether s3[0:i+j-1] is formed by an interleaving of s1[0:i-1] and s2[0:j-1]

dp[i][j] =
(dp[i][j-1] && s2[j-1] == s3[i+j-1])
||
(dp[i-1][j] && s1[i-1] == s3[i+j-1])

initial conditions: 
    dp[0][0] = true
    dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1]
    dp[i][0] = dp[i - 1][0] && s1[i-1] == s3[i-1]
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n; j++) {
            if (s2[j - 1] != s3[j - 1]) break;
            dp[j] = dp[j - 1];
        }
        for (int i = 1; i <= m; i++) {
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; j++) {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n];
    }
};
