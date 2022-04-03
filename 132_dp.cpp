/*
一开始想的状态是dp[i][j]代表i，j之间最少分割次数
转移方程为遍历i-j中间所有划分，分割成两部分计算最小的分割次数，复杂度为O(n^3)，有点太复杂；
最小分割的仅出现在回文串处，否则就是在原来基础多加一刀；因此没有必要计算所有的dp[i][j]，只用计算dp[0][j]即可
状态切换为dp[i]为0-i处的最小分割次数；再利用palindrome[i][j]记录
*/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;
        vector<vector<int>> palindrome(n, vector<int>(n, 1));
        for (int len = 1; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                palindrome[i][j] = s[i] == s[j] && palindrome[i + 1][j - 1];
            }
        }
        vector<int> dp(n, n);
        for (int i = 0; i < n; i++) {
            if (palindrome[0][i]) {
                dp[i] = 0;
            } else {
                for (int k = 1; k <= i; k++) {
                    if (palindrome[k][i]) {
                        dp[i] = min(dp[i], (k >= 1 ? dp[k-1] : 0) + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
