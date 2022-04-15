/*
    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation: 
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')

    dp[i][j]表示word1[:i] 与 word2[:j] 最小的编辑距离
    if (word1[i] == word2[j) {
        dp[i][j] = dp[i - 1][j - 1];
    } else {
        dp[i][j] = min{dp[i - 1][j - 1], dp[i][j-1], dp[i-1][j]} + 1
    }
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<int> dp(len2 + 1, 0);
        for (int i = 0; i < len2; i++) {
            dp[i + 1] = i + 1;
        }
        for (int i = 0; i < len1; i++) {
            int pre = dp[0];
            dp[0] = i + 1;
            for (int j = 0; j < len2; j++) {
                int tmp = dp[j + 1];
                if (word1[i] == word2[j]) {
                    dp[j + 1] = pre;
                } else {
                    dp[j + 1] = min(min(dp[j + 1], dp[j]), pre) + 1;
                }
                pre = tmp;
            }
        }
        return dp[len2];
    }
};


"horse"
"ros"
i: 1, j: 1, val: 1
i: 1, j: 2, val: 2
i: 1, j: 3, val: 3
i: 2, j: 1, val: 2
i: 2, j: 2, val: 1
i: 2, j: 3, val: 2
i: 3, j: 1, val: 2
i: 3, j: 2, val: 3
i: 3, j: 3, val: 2
i: 4, j: 1, val: 4
i: 4, j: 2, val: 3
i: 4, j: 3, val: 3
i: 5, j: 1, val: 5
i: 5, j: 2, val: 5
i: 5, j: 3, val: 4

