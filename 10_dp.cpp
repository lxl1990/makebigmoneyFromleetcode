/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

if p[j] == '*'
    dp[i][j] = dp[i][j-2] || (dp[i-1][j-2] || dp[i-1][j]) && charMatch(s[i], p[j-1])
else:
    dp[i][j] = dp[i-1][j-1] && charMatch(s[i], p[j])
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<bool> dp(len2 + 1, false);
        dp[0] = true;
        int i = 0;
        while (i + 1 < len2 && p[i + 1] == '*') {
            dp[i + 2] = true;
            i += 2;
        }
        auto charMatch = [](char s, char p) {
            return s == p || p == '.';
        };
        for (int i = 0; i < len1; i++) {
            bool ppre = false;
            bool pre = dp[0];
            dp[0] = false;
            for (int j = 0; j < len2; j++) {
                int tmpPre = dp[j + 1];
                if (p[j] == '*') {
                    dp[j + 1] = j >= 1 ? (dp[j - 1] || ((ppre || dp[]) && charMatch(s[i], p[j - 1]))) : false; 
                } else {
                    dp[j + 1] = pre && charMatch(s[i], p[j]);
                }
                ppre = pre;
                pre = tmpPre;
                cout << "i: " << i + 1 << ", j: " << j + 1 << ", val: " << dp[j + 1] << endl;
            }
        }
        return dp[len2];
    }
};


"aaa"
".*"
i: 1, j: 1, val: 1
i: 1, j: 2, val: 1
i: 2, j: 1, val: 0
i: 2, j: 2, val: 1
i: 3, j: 1, val: 0
i: 3, j: 2, val: 0

