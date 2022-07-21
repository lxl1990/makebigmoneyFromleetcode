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
        for (int i = len1 - 1; i >= 0; i--) {
            int pre = dp[len2];
            for (int j = len2 - 1; j >=0; j--) {
                int tmp = dp[j];
                dp[j] += s[i] == t[j] ? pre : 0;
                pre = tmp;
            }
        }
        return (int)dp[0];
    }
};


给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

 

示例 1：

输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit
